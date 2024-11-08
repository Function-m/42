/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:22:37 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:19:53 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (!(lst && f))
		return ((void *)0);
	head = (void *)0;
	while (lst)
	{
		tail = ft_lstnew(lst->content);
		if (tail == (void *)0)
		{
			ft_lstclear(&head, del);
			return ((void *)0);
		}
		tail->content = f(tail->content);
		ft_lstadd_back(&head, tail);
		tail->next = (void *)0;
		lst = lst->next;
	}
	return (head);
}
