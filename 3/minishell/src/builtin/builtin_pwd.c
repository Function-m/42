/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:03:57 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 05:46:51 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static int	check_flag(char **cmds)
{
	int	i;
	int	size;

	i = 0;
	size = strs_len(cmds);
	while (i < size)
	{
		if (str_len(cmds[i]) > 1 && cmds[i][0] == '-')
		{
			write(2, "Minishell: pwd: options are not allowed\n", 40);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	builtin_pwd(char **cmds)
{
	char	*tmp;

	g_exit_code = 0;
	if (check_flag(cmds))
	{
		g_exit_code = 1;
		return ;
	}
	tmp = getcwd(NULL, 0);
	printf("%s\n", tmp);
}
