/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:58:34 by suham             #+#    #+#             */
/*   Updated: 2024/01/17 09:24:31 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_free_all(t_memory **memory)
{
	t_memory	*current;
	t_memory	*next;

	current = *memory;
	while (current != NULL)
	{
		next = current->next;
		free(current->address);
		free(current);
		current = next;
	}
	*memory = NULL;
}
