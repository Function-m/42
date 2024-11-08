/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:39:20 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 05:45:13 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

void	builtin_env(char **cmds, char **env)
{
	int	idx;
	int	size;

	g_exit_code = 0;
	if (strs_len(cmds) > 1)
	{
		write(2, "Minishell: env: option and arg are not allowed\n", 47);
		g_exit_code = 1;
	}
	else
	{
		idx = 0;
		size = strs_len(env);
		while (idx < size)
		{
			if (*str_find_chr(env[idx], "=") == '=')
				printf("%s\n", env[idx]);
			idx++;
		}
	}
}
