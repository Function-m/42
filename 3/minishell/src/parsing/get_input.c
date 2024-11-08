/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:49 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 21:16:59 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_get_input(t_context *context)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler_main);
	do_free(context->input, &context->memory);
	context->input = NULL;
}

int	get_input(t_context *context)
{
	init_get_input(context);
	context->input = do_readline("Minishell > ", &context->memory);
	if (context->input == NULL)
	{
		write(2, "exit\n", 5);
		do_exit(0, &context->memory);
	}
	if (context->input[0] == '\0')
		return (FAILURE);
	add_history(context->input);
	return (SUCCESS);
}
