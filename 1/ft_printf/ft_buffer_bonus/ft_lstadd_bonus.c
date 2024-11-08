/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:55 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer_bonus.h"

int	ft_lstadd(t_lst **head, void *content, size_t size, size_t flag)
{
	t_lst	*new;
	t_lst	*tail;

	if (ft_lstnew(&new) == ERROR)
		return (ERROR);
	new->content = content;
	new->size = size;
	new->flag = flag;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		tail = ft_lsttail(*head);
		tail->next = new;
	}
	return (0);
}
