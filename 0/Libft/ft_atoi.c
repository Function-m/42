/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:13:15 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 13:54:21 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	ssize_t	result;

	sign = 1;
	result = 0;
	while (*str == '\v' || *str == '\f' || *str == '\t'
		|| *str == '\r' || *str == '\n' || *str == ' ')
		++str;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	result *= sign;
	if (result > 2147483647)
		result = 2147483647;
	if (result < -2147483648)
		result = -2147483648;
	return (result);
}
