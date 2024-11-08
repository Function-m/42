/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_apply_precision_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:57:40 by suham             #+#    #+#             */
/*   Updated: 2023/06/17 22:13:03 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	__chriss(t_lst *tail, size_t *exsize)
{
	void	*new;

	if (exsize[1] >= tail->size)
		return (0);
	if (ft_null_tostr((char **)(&new), exsize[1]) == ERROR)
		return (ERROR);
	ft_memcpy(new, tail->content, exsize[1]);
	free(tail->content);
	tail->content = new;
	tail->size = exsize[1];
	return (0);
}

static void	__fillzero(char *new, size_t newsize)
{
	while (newsize-- > 0)
		*new++ = '0';
}

static int	__resize(t_lst *tail, size_t *exsize)
{
	int		pfsize;
	void	*new;
	size_t	newsize;

	pfsize = 0;
	if (exsize[1] <= tail->size + pfsize)
		return (0);
	else
		newsize = exsize[1] - (tail->size + pfsize);
	if (ft_null_tostr((char **)(&new), newsize) == ERROR)
		return (ERROR);
	__fillzero((char *)new, newsize);
	if (ft_bufjoin(&new, newsize, &(tail->content), tail->size) == ERROR)
	{
		free(new);
		return (ERROR);
	}
	tail->size += newsize;
	tail->content = new;
	return (0);
}

int	_ftpf_apply_precision(t_lst *tail, char chr, size_t *exsize)
{
	if (!(tail->flag & F_PRECISION))
		return (0);
	if (chr == 's')
		return (__chriss(tail, exsize));
	else if ((chr != 'c')
		&& !(tail->flag & F_ZERO) && (exsize[1] == 0)
		&& (*((char *)(tail->content)) == '0'))
		tail->size = 0;
	else
		return (__resize(tail, exsize));
	return (0);
}
