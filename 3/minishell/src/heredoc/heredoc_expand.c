/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:38:44 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/24 13:44:50 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static void	not_expand(char **new, char **ptr, t_memory **memory)
{
	char	*start;

	start = *ptr;
	while (**ptr && **ptr != '$')
		(*ptr)++;
	*new = str_join(*new, start, *ptr - start, memory);
}

void	heredoc_expand(t_token *head, char **env, int type, t_memory **memory)
{
	char	*new;
	t_token	*current;
	char	*ptr;

	if (type == HEREDOC_END_WITH_QUOTE)
		return ;
	current = head;
	while (current != NULL)
	{
		new = NULL;
		ptr = current->value;
		while (*ptr)
		{
			if (*ptr == '$')
				env_expand(&new, &ptr, env, memory);
			else
				not_expand(&new, &ptr, memory);
		}
		do_free(current->value, memory);
		current->value = new;
		current = current->next;
	}
	return ;
}
