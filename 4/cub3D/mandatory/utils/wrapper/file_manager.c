/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:06:34 by suham             #+#    #+#             */
/*   Updated: 2024/02/15 23:07:41 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

typedef struct s_fd_node
{
	int					fd;
	struct s_fd_node	*next;
}	t_fd_node;

static t_fd_node	**get_fd_head(void)
{
	static t_fd_node	*head = NULL;

	return (&head);
}

int	do_open(char *path, int flags)
{
	t_fd_node	*new_node;
	t_fd_node	**head;
	int			fd;

	new_node = do_calloc(sizeof(t_fd_node));
	fd = open(path, flags);
	if (fd == -1)
	{
		perror("Error\nopen");
		do_exit(EXIT_FAILURE);
	}
	head = get_fd_head();
	new_node->fd = fd;
	new_node->next = *head;
	*head = new_node;
	return (fd);
}

void	do_close(int fd)
{
	t_fd_node	**head;
	t_fd_node	*current;
	t_fd_node	*prev;

	head = get_fd_head();
	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (close(current->fd) == -1)
				perror("Error\nclose");
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			do_free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	do_close_all(void)
{
	t_fd_node	**head;
	t_fd_node	*current;
	t_fd_node	*temp;

	head = get_fd_head();
	current = *head;
	while (current)
	{
		if (close(current->fd) == -1)
			perror("Error\nclose");
		temp = current;
		current = current->next;
		do_free(temp);
	}
	*head = NULL;
}
