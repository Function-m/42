/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unum_tostr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:55 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer_bonus.h"

int	ft_unum_tostr(char **new, size_t unum, int base, int upper)
{
	size_t	newlen;

	newlen = ft_strlen_unum(unum, base);
	if (ft_null_tostr(new, newlen) == ERROR)
		return (ERROR);
	while (newlen != 0)
	{
		*(*new + --newlen) = DIGIT[unum % base + 16 * upper];
		unum /= base;
	}
	return (0);
}
