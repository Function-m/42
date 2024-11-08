/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:03:26 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 22:22:33 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*do_malloc(size_t size, t_memory **memory)
{
	char	*new;

	new = malloc(size);
	if (new == NULL)
	{
		perror("Fatal Error: malloc\n");
		do_exit(1, memory);
	}
	return (new);
}

void	*do_calloc(size_t size, t_memory **memory)
{
	t_memory	*new_memory;
	void		*new;

	if (size == 0 || memory == NULL)
		return (NULL);
	new = do_malloc(size, memory);
	while (size--)
		((char *)new)[size] = 0;
	new_memory = do_malloc(sizeof(t_memory), memory);
	new_memory->address = new;
	if (*memory == NULL)
		new_memory->next = NULL;
	else
		new_memory->next = *memory;
	*memory = new_memory;
	return (new);
}
