/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:53:55 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:49:56 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	templen;

	if (*needle)
	{
		while (1)
		{
			if (!*haystack || !len--)
				return ((void *)0);
			if (*haystack == *needle)
			{
				templen = ft_strlen(needle);
				if (len < templen - 1)
					return ((void *)0);
				if (!ft_strncmp(haystack, needle, templen))
					break ;
			}
			++haystack;
		}
	}
	return ((char *)haystack);
}
