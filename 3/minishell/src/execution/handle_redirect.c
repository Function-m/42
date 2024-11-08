/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:35:46 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 21:36:52 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_infile(char *target, t_memory **memory)
{
	int	file;

	file = open(target, O_RDONLY, 0644);
	if (file == -1)
	{
		write(2, "Minishell: ", 11);
		write(2, target, str_len(target));
		write(2, ": No such file or directory\n", 28);
		do_exit(1, memory);
	}
	do_dup2(file, 0, "dup2 in handle_infile.");
}

void	handle_outfile(char *target, t_memory **memory)
{
	int	file;

	file = open(target, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		write(2, "Minishell: ", 11);
		write(2, target, str_len(target));
		write(2, ": No such file or directory\n", 28);
		do_exit(1, memory);
	}
	do_dup2(file, 1, "dup2 in handle_outfile.");
}

void	handle_outfile_append(char *target, t_memory **memory)
{
	int	file;

	file = open(target, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (file == -1)
	{
		write(2, "Minishell: ", 11);
		write(2, target, str_len(target));
		write(2, ": No such file or directory\n", 28);
		do_exit(1, memory);
	}
	do_dup2(file, 1, "dup2 in handle_outfile_append.");
}
