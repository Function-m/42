/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_read_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:06:27 by suham             #+#    #+#             */
/*   Updated: 2023/06/14 07:13:59 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	_ftpf_read(t_lst **head, char *str, va_list *argp)
{
	t_lst	*tail;
	size_t	exsize[2];

	while (1)
	{
		if (_ftpf_read_str(head, &str) == ERROR)
			return (ERROR);
		if (*str == '\0')
			return (0);
		++str;
		if (ft_lstadd(head, NULL, 0, 0) == ERROR)
			return (ERROR);
		tail = ft_lsttail(*head);
		if (_ftpf_extra_read(tail, &str, exsize) == ERROR)
			return (ERROR);
		if (_ftpf_read_arg_one(tail, *str, argp) == ERROR)
			return (ERROR);
		if (_ftpf_extra_apply(tail, *str, exsize) == ERROR)
			return (ERROR);
		++str;
	}
}
