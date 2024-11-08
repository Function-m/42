/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:11:32 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:19:53 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;

	if (s == (void *)0)
		return ((void *)0);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	slen = ft_strlen(s + start);
	if (slen < len)
		len = slen;
	ptr = malloc(len + 1);
	if (!ptr)
		return ((void *)0);
	ft_memcpy(ptr, s + start, len);
	*(ptr + len) = '\0';
	return (ptr);
}
