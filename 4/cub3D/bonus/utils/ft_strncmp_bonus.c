/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:05:37 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	ft_strncmp(char *str_1, char *str_2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- && *str_1 && (*str_1 == *str_2))
	{
		if (n == 0 || (*str_1 == '\0' && *str_2 == '\0'))
			return (0);
		str_1++;
		str_2++;
	}
	return (*str_1 - *str_2);
}
