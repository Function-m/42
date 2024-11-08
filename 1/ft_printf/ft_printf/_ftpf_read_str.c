/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ftpf_read_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:06:27 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 08:33:10 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_ftpf_read_str(t_lst **head, char **str)
{
	char	*start;
	char	*new;
	size_t	newsize;

	start = *str;
	*str = ft_strchr(*str, '%');
	newsize = *str - start;
	if (ft_str_tostr(&new, start, newsize) == ERROR)
		return (ERROR);
	if (ft_lstadd(head, (void *)new, newsize, 0) == ERROR)
	{
		free(new);
		return (ERROR);
	}
	return (0);
}
