/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:53:24 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:37:17 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	size = size * count;
	ptr = malloc(size);
	if (ptr == (void *)0)
		return (ptr);
	ft_bzero(ptr, size);
	return (ptr);
}
