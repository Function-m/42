/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcombine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 08:49:45 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

int	ft_lstcombine(t_lst **head)
{
	void	*new;
	size_t	newsize;
	t_lst	*next;

	if (ft_null_tostr((char **)&new, 0) == ERROR)
		return (ERROR);
	newsize = 0;
	while (*head != NULL)
	{
		next = (*head)->next;
		if (ft_bufjoin(&new, newsize, &((*head)->content), (*head)->size))
		{
			free(new);
			return (ERROR);
		}
		newsize += (*head)->size;
		free(*head);
		*head = next;
	}
	if (ft_lstadd(head, new, newsize, 0) == ERROR)
	{
		free(new);
		return (ERROR);
	}
	return (0);
}
