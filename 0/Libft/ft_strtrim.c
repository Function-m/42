/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:30:51 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:19:58 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ptr;

	if (s1 == (void *)0 || set == (void *)0)
		return ((void *)0);
	if (!(*s1 && *set))
		return (ft_strdup((char *)s1));
	while (ft_strchr(set, *s1))
		if (!*++s1)
			return (ft_calloc(1, 1));
	start = (char *)s1;
	while (*(s1 + 1))
		++s1;
	while (ft_strchr(set, *s1))
		--s1;
	end = (char *)s1 + 1;
	ptr = malloc(end - start + 1);
	if (!ptr)
		return ((void *)0);
	ft_memcpy(ptr, start, end - start);
	*(ptr + (end - start)) = '\0';
	return (ptr);
}
