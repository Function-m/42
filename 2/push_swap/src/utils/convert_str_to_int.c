/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str_to_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:56:56 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 09:21:18 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define POSITIVE 1
#define NEGATIVE -1

static int	check_sign(const char **str)
{
	int	sign;

	if (**str == '-')
	{
		sign = NEGATIVE;
		++(*str);
		if (**str == '\0')
			handle_exit(ERR_INVALID_ARGUMENT);
	}
	else
		sign = POSITIVE;
	return (sign);
}

static t_ll	convert_str_to_ll(const char **str)
{
	t_ll	result;

	result = 0;
	while (is_numeric(**str))
	{
		result = result * 10 + (**str - '0');
		++(*str);
	}
	if (**str != '\0')
		handle_exit(ERR_INVALID_ARGUMENT);
	return (result);
}

static void	validate_result(const char *str, t_ll result)
{
	if (result > _INT_MAX || result < _INT_MIN)
		handle_exit(ERR_INVALID_ARGUMENT);
	if (get_strlen(str) != get_numlen(result) + (t_ull)(result <= NEGATIVE))
		handle_exit(ERR_INVALID_ARGUMENT);
}

int	convert_str_to_int(const char *str)
{
	const char	*ptr;
	t_ll		result;
	int			sign;

	ptr = str;
	sign = check_sign(&ptr);
	result = convert_str_to_ll(&ptr);
	validate_result(str, result);
	return (result * sign);
}
