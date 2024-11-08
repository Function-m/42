/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:53:38 by suham             #+#    #+#             */
/*   Updated: 2023/04/09 14:53:27 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;
	size_t			i;

	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (from == to)
		return (dst);
	i = 0;
	while (i++ < n)
		*to++ = *from++;
	return (dst);
}
