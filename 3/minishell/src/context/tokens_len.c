/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:21:03 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 06:57:17 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokens_len(t_tokens *head)
{
	t_tokens	*current;
	int			cnt;

	current = head;
	cnt = 0;
	while (current != NULL)
	{
		cnt++;
		current = current->next;
	}
	return (cnt);
}
