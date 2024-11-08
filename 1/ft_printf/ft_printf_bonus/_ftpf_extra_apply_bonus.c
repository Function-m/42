/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_extra_apply_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:13:10 by suham             #+#    #+#             */
/*   Updated: 2023/06/18 09:41:52 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	__filter(t_lst *tail, char chr, size_t *exsize)
{
	if (tail->flag == 0 && exsize[0] == 0 && exsize[1] == 0)
		return (1);
	if (chr == 'c')
		tail->flag &= ~F_PRECISION;
	if (tail->flag & F_SWAP)
		tail->flag &= ~F_ZERO;
	if (exsize[1] > 0 && chr != 'c')
		tail->flag &= ~F_ZERO;
	if ((chr == 'x' || chr == 'X') \
		&& (*((char *)(tail->content)) == '0' && tail->size == 1))
		tail->flag &= ~F_SHARP;
	if (tail->flag & F_ZERO)
	{
		exsize[1] = exsize[0];
		exsize[0] = 0;
		tail->flag |= F_PRECISION;
		if (exsize[1] >= 1 && tail->flag & (F_PLUS | F_WHITE | F_NEGATIVE))
			exsize[1] -= 1;
		if (exsize[1] >= 2 && tail->flag & (F_SHARP | F_PTR))
			exsize[1] -= 2;
	}
	return (0);
}

int	_ftpf_extra_apply(t_lst *tail, char chr, size_t *exsize)
{
	if (__filter(tail, chr, exsize))
		return (0);
	if (_ftpf_apply_rmprefix(tail) == ERROR)
		return (ERROR);
	if (_ftpf_apply_precision(tail, chr, exsize) == ERROR)
		return (ERROR);
	if (_ftpf_apply_addprefix(tail, chr) == ERROR)
		return (ERROR);
	if (_ftpf_apply_width(tail, exsize) == ERROR)
		return (ERROR);
	return (0);
}
