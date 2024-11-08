/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_apply_addprefix_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:57:40 by suham             #+#    #+#             */
/*   Updated: 2023/06/14 15:51:42 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	__joinprefix(t_lst *tail, char *prefix, int pfsize)
{
	void	*new;

	if (ft_null_tostr((char **)(&new), pfsize) == ERROR)
		return (ERROR);
	ft_memcpy(new, prefix, pfsize);
	if (ft_bufjoin(&new, pfsize, &(tail->content), tail->size))
	{
		free(new);
		return (ERROR);
	}
	tail->size += pfsize;
	tail->content = new;
	return (0);
}

int	_ftpf_apply_addprefix(t_lst *tail, char chr)
{
	if ((chr == 'd' || chr == 'i') && (tail->flag & F_NEGATIVE))
		return (__joinprefix(tail, "-", 1));
	else if ((chr == 'd' || chr == 'i') && (tail->flag & F_PLUS))
		return (__joinprefix(tail, "+", 1));
	else if ((chr == 'd' || chr == 'i') && (tail->flag & F_WHITE))
		return (__joinprefix(tail, " ", 1));
	else if (chr == 'x' && (tail->flag & F_SHARP))
		return (__joinprefix(tail, "0x", 2));
	else if (chr == 'X' && (tail->flag & F_SHARP))
		return (__joinprefix(tail, "0X", 2));
	else if (tail->flag & F_PTR)
		return (__joinprefix(tail, "0x", 2));
	return (0);
}
