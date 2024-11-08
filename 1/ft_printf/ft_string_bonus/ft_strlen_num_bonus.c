/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_num_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:30:56 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_bonus.h"

size_t	ft_strlen_num(long long num, int base)
{
	size_t	length;

	length = 0;
	if (num < 0)
		++length;
	while (1)
	{
		num /= base;
		++length;
		if (num == 0)
			return (length);
	}
}
