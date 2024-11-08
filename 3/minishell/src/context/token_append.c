/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:04:14 by suham             #+#    #+#             */
/*   Updated: 2024/01/18 22:40:26 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_append(t_token **head, char *value, t_memory **memory)
{
	t_token	*new_token;
	t_token	*token_tail;

	new_token = do_calloc(sizeof(t_token), memory);
	new_token->value = value;
	new_token->type = COMMON;
	new_token->next = NULL;
	if (*head == NULL)
		*head = new_token;
	else
	{
		token_tail = *head;
		while (token_tail->next != NULL)
			token_tail = token_tail->next;
		token_tail->next = new_token;
	}
}
