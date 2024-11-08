/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_tostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 08:56:08 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

static int	__negative(char **new, long num, int base, int upper)
{
	char	*temp;

	if (num == -0x80000000)
	{
		if (ft_str_tostr(new, "-2147483648", 11) == ERROR)
			return (ERROR);
		return (0);
	}
	if (ft_unum_tostr(&temp, -1 * num, base, upper) == ERROR)
		return (ERROR);
	if (ft_chr_tostr(new, '-') == ERROR)
	{
		free(temp);
		return (ERROR);
	}
	if (ft_bufjoin((void **)new, 1, (void **)(&temp),
		ft_strlen(temp) + 1) == ERROR)
	{
		free(*new);
		free(temp);
		return (ERROR);
	}
	return (0);
}

int	ft_num_tostr(char **new, long num, int base, int upper)
{
	if (num < 0)
		return (__negative(new, num, base, upper));
	else
		return (ft_unum_tostr(new, num, base, upper));
}
