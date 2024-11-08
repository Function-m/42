/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_get_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:54:24 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 14:06:27 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tokens_get_cmd(t_tokens *head, t_memory **memory)
{
	t_token	*current;
	t_token	*before;
	char	*new;

	current = head->token;
	before = NULL;
	new = NULL;
	while (current != NULL)
	{
		if (current->value != NULL && (before == NULL || \
		!(before->type & (FILE_OUT_APPEND | FILE_IN | FILE_OUT))))
		{
			if (current->type == COMMON)
			{
				new = str_dup(current->value, memory);
				break ;
			}
		}
		before = current;
		current = current->next;
	}
	return (new);
}
