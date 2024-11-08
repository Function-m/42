/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 08:26:01 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

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
