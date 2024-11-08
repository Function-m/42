/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstloop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:55 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer_bonus.h"

int	ft_lstloop(t_lst *head, int (*usef)(t_lst *))
{
	t_lst	*temp;

	while (head != NULL)
	{
		temp = head->next;
		if (usef(head) == ERROR)
			return (ERROR);
		head = temp;
	}
	return (0);
}
