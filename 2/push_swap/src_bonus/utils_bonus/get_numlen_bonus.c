/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 02:05:30 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 12:11:05 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	get_numlen(int number)
{
	int	length;

	if (number == 0)
		return (1);
	if (number < 0)
		number *= -1;
	length = 0;
	while (number > 0)
	{
		number /= 10;
		++length;
	}
	return (length);
}
