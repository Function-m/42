/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:41:55 by suham             #+#    #+#             */
/*   Updated: 2024/02/15 23:07:52 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}	t_mem_node;

static t_mem_node	**get_head(void)
{
	static t_mem_node	*head = NULL;

	return (&head);
}

static void	*do_malloc(size_t size)
{
	void		*new_mem;
	t_mem_node	**head;
	t_mem_node	*new_node;

	head = get_head();
	new_mem = malloc(size);
	new_node = malloc(sizeof(t_mem_node));
	if (!new_mem || !new_node)
	{
		perror("Error\nmalloc");
		do_exit(EXIT_FAILURE);
	}
	new_node->address = new_mem;
	new_node->next = *head;
	*head = new_node;
	return (new_mem);
}

void	*do_calloc(size_t size)
{
	char	*new_mem;
	size_t	i;

	if (size == 0)
		size = 1;
	new_mem = do_malloc(size);
	i = 0;
	while (i < size)
	{
		new_mem[i] = 0;
		i++;
	}
	return ((void *)new_mem);
}

void	do_free(void *target)
{
	t_mem_node	**head;
	t_mem_node	*current;
	t_mem_node	*prev;

	head = get_head();
	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		if (current->address == target)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->address);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	do_free_all(void)
{
	t_mem_node	**head;
	t_mem_node	*current;
	t_mem_node	*temp;

	head = get_head();
	current = *head;
	while (current != NULL)
	{
		free(current->address);
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}
