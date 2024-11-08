/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:44 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/23 16:22:03 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_len(t_token *head)
{
	int		cnt;
	t_token	*current;

	cnt = 0;
	current = head;
	while (current != NULL)
	{
		cnt++;
		current = current->next;
	}
	return (cnt);
}
