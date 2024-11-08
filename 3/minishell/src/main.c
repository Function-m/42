/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:24:57 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 20:48:29 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code;

static void	validate_main_arg(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc > 1)
	{
		write(2, "Minishell does not receive arguments.\n", 38);
		exit(1);
	}
	if (envp == NULL)
	{
		write(2, "Environmental variables are not found.\n", 39);
		exit(1);
	}
}

static void	init_main(t_context *context, char **envp)
{
	context->memory = NULL;
	context->input = NULL;
	context->raw_token = NULL;
	context->tokens = NULL;
	context->cmd_cnt = 0;
	context->fd[0] = 0;
	context->fd[1] = 0;
	context->before_out_fd = 0;
	context->env = strs_dup(envp, &context->memory);
	context->home = env_get_value("HOME", context->env, &context->memory);
	g_exit_code = 0;
}

static void	run_main_routine(t_context *context)
{
	while (TRUE)
	{
		if (get_input(context) == FAILURE)
			continue ;
		if (parse_input_to_tokens(context) == FAILURE)
			continue ;
		if (execute_tokens_as_cmd(context) == FAILURE)
			continue ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_context	context;

	validate_main_arg(argc, argv, envp);
	init_main(&context, envp);
	run_main_routine(&context);
	do_exit(0, &context.memory);
}
