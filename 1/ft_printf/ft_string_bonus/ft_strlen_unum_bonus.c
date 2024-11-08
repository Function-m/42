/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_unum_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:30:56 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_bonus.h"

size_t	ft_strlen_unum(size_t unum, int base)
{
	size_t	length;

	length = 0;
	while (1)
	{
		unum /= base;
		++length;
		if (unum == 0)
			return (length);
	}
}
