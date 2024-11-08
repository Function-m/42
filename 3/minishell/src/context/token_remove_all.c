/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_remove_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:29:51 by suham             #+#    #+#             */
/*   Updated: 2024/01/22 00:12:19 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_remove_all(t_token *head, t_memory **memory)
{
	t_token	*next_token;

	while (head != NULL)
	{
		next_token = head->next;
		if (head->value)
			do_free(head->value, memory);
		do_free(head, memory);
		head = next_token;
	}
}
