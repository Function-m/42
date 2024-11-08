/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_extra_read_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:08:47 by suham             #+#    #+#             */
/*   Updated: 2023/06/18 10:38:45 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	__str_tonum(t_lst *tail, char **str, size_t *exsize)
{
	exsize[0] = 0;
	exsize[1] = 0;
	while (**str >= '0' && **str <= '9')
	{
		exsize[0] = exsize[0] * 10 + **str - '0';
		++(*str);
	}
	if (**str != '.')
		return ;
	++(*str);
	tail->flag |= F_PRECISION;
	tail->flag &= ~F_ZERO;
	while (**str >= '0' && **str <= '9')
	{
		exsize[1] = exsize[1] * 10 + **str - '0';
		++(*str);
	}
}

int	_ftpf_extra_read(t_lst *tail, char **str, size_t *exsize)
{
	while (1)
	{
		if (**str == '#')
			tail->flag |= F_SHARP;
		else if (**str == '+')
			tail->flag |= F_PLUS;
		else if (**str == ' ')
			tail->flag |= F_WHITE;
		else if (**str == '-')
			tail->flag |= F_SWAP;
		else if (**str == '0')
			tail->flag |= F_ZERO;
		else
			break ;
		++(*str);
	}
	__str_tonum(tail, str, exsize);
	return (0);
}
