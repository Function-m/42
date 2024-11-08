/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:32:58 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 05:42:46 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static int	is_n_flag(char **cmd, int cnt)
{
	int	idx;

	idx = 1;
	if (cmd[cnt][0] == '-')
	{
		while (cmd[cnt][idx] == 'n')
			idx++;
		if (cmd[cnt][idx] == '\0')
			return (TRUE);
	}
	return (FALSE);
}

void	builtin_echo(char **cmds)
{
	int		idx;
	int		cnt_cmd;
	int		n_flag;
	int		is_first;

	g_exit_code = 0;
	idx = 1;
	cnt_cmd = strs_len(cmds);
	n_flag = 0;
	is_first = 1;
	while (idx < cnt_cmd && is_n_flag(cmds, idx) == TRUE)
	{
		n_flag = 1;
		idx++;
	}
	while (idx < cnt_cmd)
	{
		printf("%s", cmds[idx]);
		idx++;
		if (idx < cnt_cmd)
			printf(" ");
	}
	if (n_flag == 0)
		printf("\n");
}
