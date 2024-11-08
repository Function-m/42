/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:45:04 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/24 20:14:59 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check(char *c)
{
	int		i;
	int		sign;
	int		value;

	i = 0;
	sign = 1;
	value = 0;
	while ((c[i] >= 9 && c[i] <= 13) || c[i] == 32)
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			sign *= -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		value = value * 10 + (c[i] - '0');
		i++;
	}
	return (value * sign);
}

int	str_atoi(char *str)
{
	int		value;

	value = check(str);
	return (value);
}
