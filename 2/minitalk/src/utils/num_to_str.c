/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:08:07 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 17:18:35 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	get_digit_count(long long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		++ count;
	}
	return (count);
}

char	*num_to_str(long long num)
{
	char		*new_str;
	int			is_negative;
	long long	new_str_size;
	int			i;

	is_negative = FALSE;
	if (num < 0)
	{
		is_negative = TRUE;
		num = -num;
	}
	new_str_size = get_digit_count(num) + (is_negative == TRUE) + 1;
	new_str = malloc(new_str_size);
	if (new_str == _NULL)
		handle_exit(ERR_MALLOC);
	i = new_str_size - 1;
	new_str[i] = '\0';
	while (i -- >= (is_negative == TRUE))
	{
		new_str[i] = num % 10 + '0';
		num /= 10;
	}
	if (is_negative == TRUE)
		new_str[0] = '-';
	return (new_str);
}
