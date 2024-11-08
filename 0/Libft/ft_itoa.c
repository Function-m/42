/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:14:47 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:19:53 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	if (n < 0)
		n *= -1;
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	else
		return (10);
}

char	*ft_itoa(int n)
{
	long	temp;
	int		length;
	char	*ptr;

	temp = n;
	temp *= -(n < 0) | (n > 0);
	length = ft_intlen(n) + (n < 0);
	ptr = malloc(length + 1);
	if (!ptr)
		return ((void *)0);
	*(ptr + length) = '\0';
	while (length--)
	{
		*(ptr + length) = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		*ptr = '-';
	return (ptr);
}
