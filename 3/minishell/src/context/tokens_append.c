/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:17:57 by suham             #+#    #+#             */
/*   Updated: 2024/01/22 17:43:11 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokens_append(t_tokens **head, t_token *token, t_memory **memory)
{
	t_tokens	*new;
	t_tokens	*tokens_tail;

	new = do_calloc(sizeof(t_tokens), memory);
	new->token = token;
	new->next = NULL;
	if (*head == NULL)
	{
		new->idx = 0;
		*head = new;
	}
	else
	{
		tokens_tail = *head;
		while (tokens_tail->next != NULL)
			tokens_tail = tokens_tail->next;
		new->idx = tokens_tail->idx + 1;
		tokens_tail->next = new;
	}
}
