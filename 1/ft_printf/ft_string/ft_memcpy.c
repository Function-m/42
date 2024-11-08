/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:30:56 by suham             #+#    #+#             */
/*   Updated: 2023/06/14 17:23:59 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_memcpy(void *dst, void *src, size_t srcsize)
{
	unsigned char	*dstp;
	unsigned char	*srcp;

	dstp = dst;
	srcp = src;
	while (srcsize-- != 0)
		*dstp++ = *srcp++;
}
