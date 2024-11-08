/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:43 by suham             #+#    #+#             */
/*   Updated: 2024/01/24 15:56:46 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*do_readline(char *prompt, t_memory **memory)
{
	char		*input;
	t_memory	*new_memory;

	input = readline(prompt);
	if (input == NULL)
		return (NULL);
	new_memory = malloc(sizeof(t_memory));
	if (new_memory == NULL)
	{
		perror("Fatal Error: malloc\n");
		do_exit(1, memory);
	}
	new_memory->address = input;
	if (*memory == NULL)
		new_memory->next = NULL;
	else
		new_memory->next = *memory;
	*memory = new_memory;
	return (input);
}
