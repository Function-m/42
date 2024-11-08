/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_apply_width_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:57:40 by suham             #+#    #+#             */
/*   Updated: 2023/06/14 16:47:42 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	__fill(char *new, size_t newsize, char c)
{
	while (newsize-- > 0)
		*new++ = c;
}

static void	__swap(void **one, void **two, size_t *onesize, size_t *twosize)
{
	void	*temp;

	temp = *one;
	*one = *two;
	*two = temp;
	*onesize ^= *twosize;
	*twosize ^= *onesize;
	*onesize ^= *twosize;
}

int	_ftpf_apply_width(t_lst *tail, size_t *exsize)
{
	void	*new;
	size_t	newsize;

	if (exsize[0] < tail->size)
		return (0);
	newsize = exsize[0] - tail->size;
	if (ft_null_tostr((char **)(&new), newsize) == ERROR)
		return (ERROR);
	__fill((char *)new, newsize, ' ');
	if (!(tail->flag & F_SWAP))
		__swap(&new, &(tail->content), &newsize, &(tail->size));
	if (ft_bufjoin(&(tail->content), tail->size, &new, newsize))
	{
		free(new);
		return (ERROR);
	}
	tail->size += newsize;
	return (0);
}
