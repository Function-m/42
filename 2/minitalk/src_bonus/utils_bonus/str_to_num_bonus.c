/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_num_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:58:21 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 17:17:17 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

long long	str_to_num(const char *str)
{
	long long	new_num;
	int			is_negative;

	new_num = 0;
	is_negative = FALSE;
	if (*str == '-')
	{
		is_negative = TRUE;
		++ str;
	}
	while (*str >= '0' && *str <= '9')
	{
		new_num = new_num * 10 + (*str - '0');
		++ str;
	}
	if (*str != '\0')
		handle_exit(ERR_ARGUMENT);
	if (is_negative == TRUE)
		new_num = -new_num;
	return (new_num);
}
