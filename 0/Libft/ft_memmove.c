/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:53:40 by suham             #+#    #+#             */
/*   Updated: 2023/04/09 14:56:34 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (from == to || !len)
		return (dst);
	if (to > from && to - from < (int)len)
		while (len--)
			*(to + len) = *(from + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
