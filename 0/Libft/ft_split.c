/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 03:32:41 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:19:53 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **ptr, size_t count)
{
	while (ptr[count + 1])
		free(ptr[count++ + 1]);
	free(ptr);
	return ((void *)0);
}

static char	**ft_recursive_split(char *s, char c, size_t count)
{
	char	*start;
	char	**ptr;

	while (*s && *s == c)
		++s;
	start = s;
	while (*s && *s != c)
		++s;
	count -= start == s;
	if (!*s)
		ptr = malloc(sizeof(char *) * (count + 2));
	else
		ptr = ft_recursive_split(s, c, count + 1);
	if (!ptr)
		return ((void *)0);
	if (!*s)
		ptr[count + 1] = (void *)0;
	if (start == s)
		return (ptr);
	ptr[count] = malloc(s - start + 1);
	if (!ptr[count])
		return (ft_freeall(ptr, count));
	ft_strlcpy(ptr[count], start, s - start + 1);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	return (ft_recursive_split((char *)s, c, 0));
}
