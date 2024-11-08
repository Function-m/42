/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unum_tostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/11 06:32:18 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

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
