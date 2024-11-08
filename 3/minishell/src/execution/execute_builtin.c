/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:11:52 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 06:45:09 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin(t_context *context, char **cmds)
{
	char	*cmd;

	cmd = cmds[0];
	if (str_cmp(cmd, "cd") == 0)
		builtin_cd(context, cmds);
	else if (str_cmp(cmd, "echo") == 0)
		builtin_echo(cmds);
	else if (str_cmp(cmd, "env") == 0)
		builtin_env(cmds, context->env);
	else if (str_cmp(cmd, "exit") == 0)
		builtin_exit(cmds, &context->memory);
	else if (str_cmp(cmd, "export") == 0)
		builtin_export(context, cmds);
	else if (str_cmp(cmd, "pwd") == 0)
		builtin_pwd(cmds);
	else if (str_cmp(cmd, "unset") == 0)
		builtin_unset(context, cmds);
}
