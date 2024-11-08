/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:40:37 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 08:07:03 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

int	ft_bufjoin(void **dst, size_t dstsize, void **src, size_t srcsize)
{
	void	*new;

	new = malloc(dstsize + srcsize);
	if (new == NULL)
		return (ERROR);
	ft_memcpy(new, *dst, dstsize);
	free(*dst);
	ft_memcpy(new + dstsize, *src, srcsize);
	free(*src);
	*dst = new;
	return (0);
}
