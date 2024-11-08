/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:06:27 by suham             #+#    #+#             */
/*   Updated: 2023/06/14 08:59:24 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	va_list	argp;
	t_lst	*head;

	head = NULL;
	va_start(argp, str);
	if (str == NULL)
		return (ERROR);
	if (_ftpf_read(&head, (char *)str, &argp) == ERROR)
		return (_ftpf_end(&head, &argp, ERROR));
	if (_ftpf_print(&head) == ERROR)
		return (_ftpf_end(&head, &argp, ERROR));
	return (_ftpf_end(&head, &argp, head->size));
}
