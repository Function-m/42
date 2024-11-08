/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:06:27 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:30 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	_ftpf_print(t_lst **head)
{
	if ((*head)->next != NULL)
	{
		if (ft_lstcombine(head) == ERROR)
			return (ERROR);
	}
	if ((*head)->size > 0x7FFFFFFE)
		return (ERROR);
	if (write(1, (*head)->content, (*head)->size) == ERROR)
		return (ERROR);
	return (0);
}
