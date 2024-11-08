/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_read_arg_one_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:06:27 by suham             #+#    #+#             */
/*   Updated: 2023/06/18 10:36:31 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	__buf_chr(t_lst *tail, int chr)
{
	char	*new;

	if (ft_chr_tostr(&new, (char)chr) == ERROR)
		return (ERROR);
	tail->content = (void *)new;
	tail->size = 1;
	return (0);
}

static int	__buf_str(t_lst *tail, char *str)
{
	char	*new;
	size_t	newlen;

	if (str == NULL)
		str = "(null)";
	newlen = ft_strlen(str);
	if (ft_str_tostr(&new, str, newlen) == ERROR)
		return (ERROR);
	tail->content = (void *)new;
	tail->size = newlen;
	return (0);
}

static int	__buf_ptr(t_lst *tail, size_t ptr)
{
	char	*new;
	char	*temp;
	size_t	newlen;

	if (ft_str_tostr(&new, "0x", 2) == ERROR)
		return (ERROR);
	if (ft_unum_tostr(&temp, ptr, 16, 0) == ERROR)
	{
		free(new);
		return (ERROR);
	}
	newlen = ft_strlen(temp);
	if (ft_bufjoin((void **)(&new), 2, (void **)(&temp),
		newlen) == ERROR)
	{
		free(new);
		free(temp);
		return (ERROR);
	}
	tail->content = (void *)new;
	tail->size = newlen + 2;
	tail->flag |= F_PTR;
	return (0);
}

int	_ftpf_read_arg_one(t_lst *tail, char chr, va_list *argp)
{
	if (chr == 'c')
		return (__buf_chr(tail, va_arg(*argp, int)));
	if (chr == '%')
		return (__buf_chr(tail, '%'));
	if (chr == 's')
		return (__buf_str(tail, va_arg(*argp, char *)));
	if (chr == 'p')
		return (__buf_ptr(tail, va_arg(*argp, size_t)));
	else
		return (_ftpf_read_arg_two(tail, chr, argp));
}
