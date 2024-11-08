/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:15:58 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:49:18 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	slen;
	char			*ptr;
	unsigned int	i;

	if (!s)
		return ((void *)0);
	slen = ft_strlen(s);
	ptr = malloc(slen + 1);
	if (!ptr)
		return ((void *)0);
	i = 0;
	while (i < slen)
	{
		ptr[i] = f(i, s[i]);
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
