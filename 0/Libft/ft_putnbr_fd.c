/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:41:40 by suham             #+#    #+#             */
/*   Updated: 2023/04/10 15:51:50 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse(long n, int fd)
{
	if (!n)
		return ;
	ft_reverse(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	temp;

	temp = n;
	if (temp == 0)
		return (ft_putchar_fd('0', fd));
	if (temp < 0)
	{
		ft_putchar_fd('-', fd);
		ft_reverse(-temp, fd);
	}
	if (temp > 0)
		ft_reverse(temp, fd);
}
