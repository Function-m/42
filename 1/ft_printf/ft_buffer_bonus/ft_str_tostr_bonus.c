/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tostr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:55 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer_bonus.h"

int	ft_str_tostr(char **new, char *str, size_t length)
{
	if (ft_null_tostr(new, length) == ERROR)
		return (ERROR);
	ft_memcpy((void *)(*new), (void *)(str), length);
	return (0);
}
