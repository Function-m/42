/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect_single.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:35:46 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 21:36:52 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

int	handle_infile_single(char *target)
{
	int	file;

	file = open(target, O_RDONLY);
	if (file == -1)
	{
		write(2, "Minishell: ", 11);
		write(2, target, str_len(target));
		write(2, ": No such file or directory\n", 28);
		g_exit_code = 1;
		return (1);
	}
	do_dup2(file, 0, "dup2 in handle_infile.");
	return (0);
}

int	handle_outfile_single(char *target)
{
	int	file;

	file = open(target, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		write(2, "Minishell: ", 11);
		write(2, target, str_len(target));
		write(2, ": No such file or directory\n", 28);
		g_exit_code = 1;
		return (1);
	}
	do_dup2(file, 1, "dup2 in handle_outfile.");
	return (0);
}

int	handle_outfile_append_single(char *target)
{
	int	file;

	file = open(target, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (file == -1)
	{
		write(2, "Minishell: ", 11);
		write(2, target, str_len(target));
		write(2, ": No such file or directory\n", 28);
		g_exit_code = 1;
		return (1);
	}
	do_dup2(file, 1, "dup2 in handle_outfile_append.");
	return (0);
}
