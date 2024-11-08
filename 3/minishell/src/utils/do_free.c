/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:59:01 by suham             #+#    #+#             */
/*   Updated: 2024/01/24 15:28:24 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_free(void *target, t_memory **memory)
{
	t_memory	*current;
	t_memory	*prev;

	if (target == NULL || *memory == NULL)
		return ;
	current = *memory;
	prev = NULL;
	while (current != NULL)
	{
		if (current->address == target)
		{
			if (prev == NULL)
				*memory = current->next;
			else
				prev->next = current->next;
			free(current->address);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
