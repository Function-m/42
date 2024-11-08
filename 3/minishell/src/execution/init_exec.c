/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:09:13 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 22:19:18 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_token(t_tokens *head, int idx);
char	**get_path(char **env, t_memory **memory);
int		cnt_cmd(t_token *head);
char	**get_cmds(t_token *head, t_memory **memory);
char	*get_p_cmd(char *cmd, char **path, t_memory **memory);

t_exec	*init_exec(t_context *context, char *cmd, int idx, t_memory **memory)
{
	t_exec	*new_exec;

	new_exec = do_calloc(sizeof(t_exec), memory);
	new_exec->current_token = get_token(context->tokens, idx);
	new_exec->idx = idx;
	new_exec->pid = 0;
	new_exec->path = get_path(context->env, memory);
	new_exec->cmds = get_cmds(new_exec->current_token, memory);
	new_exec->cmd = cmd;
	new_exec->p_cmd = get_p_cmd(cmd, new_exec->path, memory);
	return (new_exec);
}
