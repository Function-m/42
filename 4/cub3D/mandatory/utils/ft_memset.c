/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 05:46:23 by suham             #+#    #+#             */
/*   Updated: 2024/02/16 14:48:54 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memset(void *dst, int chr, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)dst;
	i = 0;
	while (len > i)
	{
		*(int *)ptr = chr;
		ptr++;
		i++;
	}
	return (dst);
}
