/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:42:31 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 09:21:40 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*handle_malloc(t_ull size, t_ull type_size)
{
	char	*new;
	t_ull	new_size;
	t_ull	i;

	new_size = size * type_size;
	if (size * type_size < size)
		handle_exit(ERR_MALLOC_FAILED);
	new = malloc(new_size);
	if (new == _NULL)
		handle_exit(ERR_MALLOC_FAILED);
	i = 0;
	while (i < new_size)
	{
		new[i] = 0;
		++i;
	}
	return (new);
}
