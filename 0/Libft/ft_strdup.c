/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:53:49 by suham             #+#    #+#             */
/*   Updated: 2023/04/03 09:39:39 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(src) + 1;
	ptr = malloc(len);
	if (ptr)
		ft_memcpy(ptr, src, len);
	return (ptr);
}
