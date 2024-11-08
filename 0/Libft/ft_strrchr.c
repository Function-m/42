/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:42:29 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:50:02 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	ch;

	temp = (void *)0;
	ch = (char)c;
	while (1)
	{
		if (*s == ch)
			temp = (char *)s;
		if (*s++ == '\0')
			break ;
	}
	return (temp);
}
