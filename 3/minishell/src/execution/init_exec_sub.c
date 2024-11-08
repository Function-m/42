/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:17:45 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 13:01:06 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_token(t_tokens *head, int idx)
{
	t_tokens	*current_tokens;

	current_tokens = head;
	while (current_tokens != NULL && current_tokens->idx != idx)
		current_tokens = current_tokens->next;
	return (current_tokens->token);
}

char	**get_path(char **env, t_memory **memory)
{
	char	*path;
	char	**new_path;
	int		key_len;

	path = env_find("PATH", env, memory);
	if (path == NULL)
		return (NULL);
	key_len = str_len_until_chr(path, '=');
	path += key_len;
	new_path = str_split_by_chr(path, ':', memory);
	return (new_path);
}

int	cnt_cmd(t_token *head)
{
	int		size;
	t_token	*before;
	t_token	*current;

	size = 0;
	before = NULL;
	current = head;
	while (current != NULL)
	{
		if ((before == NULL || !(before->type & (FILE_IN | \
		FILE_OUT | FILE_OUT_APPEND))) && current->type == COMMON \
		&& current->value != NULL)
			size++;
		before = current;
		current = current->next;
	}
	return (size);
}

char	**get_cmds(t_token *head, t_memory **memory)
{
	int		size;
	int		i;
	t_token	*before;
	t_token	*current;
	char	**new_cmds;

	size = cnt_cmd(head);
	new_cmds = (char **)do_calloc(sizeof(char *) * (size + 1), memory);
	i = 0;
	before = NULL;
	current = head;
	while (current != NULL)
	{
		if ((before == NULL || !(before->type & (FILE_IN | \
		FILE_OUT | FILE_OUT_APPEND))) && current->type == COMMON \
		&& current->value != NULL)
		{
			new_cmds[i] = current->value;
			i++;
		}
		before = current;
		current = current->next;
	}
	return (new_cmds);
}

char	*get_p_cmd(char *cmd, char **path, t_memory **memory)
{
	int			i;
	char		*tmp;
	char		*final;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (cmd && path && path[i])
	{
		tmp = str_dup(path[i], memory);
		tmp = str_join(tmp, "/", 1, memory);
		final = str_join(tmp, cmd, str_len(cmd), memory);
		if (access(final, X_OK) == 0)
			return (final);
		else
			do_free(final, memory);
		i++;
	}
	return (NULL);
}
