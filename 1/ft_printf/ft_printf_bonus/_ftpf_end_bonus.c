/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_end_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:06:27 by suham             #+#    #+#             */
/*   Updated: 2023/06/18 00:34:01 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	__freeall(t_lst *head)
{
	free(head->content);
	free(head);
	return (0);
}

int	_ftpf_end(t_lst **head, va_list *argp, int return_value)
{
	va_end(*argp);
	ft_lstloop(*head, __freeall);
	return (return_value);
}
