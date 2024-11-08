/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:31:44 by suham             #+#    #+#             */
/*   Updated: 2023/04/10 15:11:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		*(dst + dstsize - 1) = '\0';
	}
	return (srclen);
}
