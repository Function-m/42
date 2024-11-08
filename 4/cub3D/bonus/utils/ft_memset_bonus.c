/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 05:46:23 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

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
