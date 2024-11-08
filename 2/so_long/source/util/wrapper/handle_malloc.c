/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 02:47:58 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 05:57:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	*handle_malloc(t_ll size)
{
	char	*new;
	t_ll	i;

	new = malloc(size);
	if (!new)
		handle_exit(FAILURE, "'malloc' function failed\n");
	i = 0;
	while (i < size)
		*(new + i++) = 0;
	return (new);
}
