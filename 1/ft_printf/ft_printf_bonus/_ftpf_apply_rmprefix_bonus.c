/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_apply_rmprefix_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:57:40 by suham             #+#    #+#             */
/*   Updated: 2023/06/14 15:14:56 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	_ftpf_apply_rmprefix(t_lst *tail)
{
	void	*new;
	int		index;

	if (tail->flag & F_PTR)
		index = 2;
	else if (tail->flag & F_NEGATIVE)
		index = 1;
	else
		return (0);
	tail->size -= index;
	if (ft_null_tostr((char **)(&new), tail->size) == ERROR)
		return (ERROR);
	ft_memcpy(new, tail->content + index, tail->size);
	free(tail->content);
	tail->content = new;
	return (0);
}
