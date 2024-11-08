/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_read_arg_two_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:06:27 by suham             #+#    #+#             */
/*   Updated: 2023/06/14 17:10:45 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	__buf_int(t_lst *tail, int num)
{
	char	*new;

	if (ft_num_tostr(&new, num, 10, 0) == ERROR)
		return (ERROR);
	tail->content = (void *)new;
	tail->size = ft_strlen(new);
	if (num < 0)
		tail->flag |= F_NEGATIVE;
	return (0);
}

static int	__buf_uint(t_lst *tail, unsigned int unum)
{
	char	*new;

	if (ft_num_tostr(&new, unum, 10, 0) == ERROR)
		return (ERROR);
	tail->content = (void *)new;
	tail->size = ft_strlen(new);
	return (0);
}

static int	__buf_hex(t_lst *tail, unsigned int hex)
{
	char	*new;

	if (ft_unum_tostr(&new, hex, 16, 0) == ERROR)
		return (ERROR);
	tail->content = (void *)new;
	tail->size = ft_strlen(new);
	return (0);
}

static int	__buf_uhex(t_lst *tail, unsigned int uhex)
{
	char	*new;

	if (ft_unum_tostr(&new, uhex, 16, 1) == ERROR)
		return (ERROR);
	tail->content = (void *)new;
	tail->size = ft_strlen(new);
	return (0);
}

int	_ftpf_read_arg_two(t_lst *tail, char chr, va_list *argp)
{
	if (chr == 'd' || chr == 'i')
		return (__buf_int(tail, va_arg(*argp, int)));
	if (chr == 'u')
		return (__buf_uint(tail, va_arg(*argp, unsigned int)));
	if (chr == 'x')
		return (__buf_hex(tail, va_arg(*argp, unsigned int)));
	if (chr == 'X')
		return (__buf_uhex(tail, va_arg(*argp, unsigned int)));
	else
		return (ERROR);
}
