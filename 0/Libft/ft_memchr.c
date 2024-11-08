/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:53:33 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:19:53 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;
	char		ch;
	size_t		i;

	ptr = (const char *)s;
	ch = (char)c;
	i = 0;
	while (i < n)
		if (*(ptr + i++) == ch)
			return ((void *)(ptr + --i));
	return ((void *)0);
}
