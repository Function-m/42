/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:30:56 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_bonus.h"

void	ft_memcpy(void *dst, void *src, size_t srcsize)
{
	unsigned char	*dstp;
	unsigned char	*srcp;

	dstp = dst;
	srcp = src;
	while (srcsize-- != 0)
		*dstp++ = *srcp++;
}
