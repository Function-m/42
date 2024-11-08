/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:16:56 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 05:43:44 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static int	validate_cmd(char *cmd)
{
	char	*ptr;

	ptr = cmd;
	if (!((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z') || \
		*ptr == '_'))
	{
		write(2, "Minishell: unset: `", 19);
		write(2, cmd, str_len(cmd));
		write(2, "' : not a valid identifier\n", 27);
		return (FALSE);
	}
	while ((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z')
		|| (*ptr >= '0' && *ptr <= '9') || (*ptr == '_'))
		ptr++;
	if (*ptr != '\0')
	{
		write(2, "Minishell: unset: `", 19);
		write(2, cmd, str_len(cmd));
		write(2, "' : not a valid identifier\n", 27);
		return (FALSE);
	}
	return (TRUE);
}

void	builtin_unset(t_context *context, char **cmds)
{
	int		cnt_cmd;
	int		i;

	g_exit_code = 0;
	cnt_cmd = strs_len(cmds);
	i = 1;
	while (i < cnt_cmd)
	{
		if (cmds[i][0] == '-')
		{
			write(2, "Minishell: pwd: options are not allowed\n", 40);
			g_exit_code = 1;
			return ;
		}
		i++;
	}
	i = 1;
	while (i < cnt_cmd)
	{
		if (validate_cmd(cmds[i]) == TRUE)
			context->env = env_delete(cmds[i], context->env, &context->memory);
		else
			g_exit_code = 1;
		i++;
	}
}
