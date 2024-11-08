/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:06:27 by suham             #+#    #+#             */
/*   Updated: 2023/06/11 06:32:51 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_ftpf_read(t_lst **head, char *str, va_list *argp)
{
	t_lst	*tail;

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
		if (_ftpf_read_arg_one(tail, *str, argp) == ERROR)
			return (ERROR);
		++str;
	}
}
