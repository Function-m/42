/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:17:12 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 05:55:45 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static int	is_num(char *cmd)
{
	int	idx;
	int	size;

	idx = 0;
	size = str_len(cmd);
	while (idx < size)
	{
		if (!(cmd[idx] >= '0' && cmd[idx] <= '9'))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

static unsigned char	set_exit_code(char *input)
{
	int				num;
	unsigned char	status;

	num = str_atoi(input);
	status = num % 256;
	return (status);
}

void	builtin_exit(char **cmds, t_memory **memory)
{
	int	cnt_cmds;
	int	input_code;

	g_exit_code = 0;
	cnt_cmds = strs_len(cmds);
	write(2, "exit\n", 5);
	if (is_num(cmds[1]) == FALSE)
	{
		write(2, "Minishell: exit: ", 17);
		write(2, cmds[1], str_len(cmds[1]));
		write(2, ": numeric argument required\n", 28);
		do_exit(255, memory);
	}
	else if (cnt_cmds > 2)
	{
		write(2, "Minishell: exit: too many arguments\n", 36);
		g_exit_code = 1;
	}
	else
	{
		input_code = 0;
		if (cnt_cmds > 1)
			input_code = set_exit_code(cmds[1]);
		do_exit(input_code, memory);
	}
}
