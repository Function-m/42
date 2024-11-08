/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_int_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:18:26 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:30 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	reverse_str(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void	handle_negative(int *num, int *is_negative)
{
	if (*num < 0 && *num != -2147483648)
	{
		*is_negative = 1;
		*num *= -1;
	}
}

void	convert_to_str(int num, char *str, int *i, int str_size)
{
	int	remainder;

	while (num != 0 && *i < str_size - 1)
	{
		remainder = num % 10;
		if (remainder > 9)
			str[*i] = remainder - 10 + 'a';
		else
			str[*i] = remainder + '0';
		num = num / 10;
		(*i)++;
	}
}

void	append_negative_sign(char *str, int *i, int is_negative)
{
	if (is_negative)
	{
		str[*i] = '-';
		(*i)++;
	}
}

void	get_str_from_int(int num, char *str, int str_size)
{
	int	i;
	int	is_negative;

	i = 0;
	is_negative = 0;
	if (num == 0)
		str[i++] = '0';
	else
	{
		handle_negative(&num, &is_negative);
		convert_to_str(num, str, &i, str_size);
		append_negative_sign(str, &i, is_negative);
	}
	str[i] = '\0';
	reverse_str(str, i);
}
