/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_chr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:35 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_chr(int tile)
{
	if (tile == MAP_EMPTY)
		return (TRUE);
	if (tile == MAP_WALL)
		return (TRUE);
	if (tile == MAP_COLLETIABLE)
		return (TRUE);
	if (tile == MAP_EXIT)
		return (TRUE);
	if (tile == MAP_PLAYER)
		return (TRUE);
	else
		return (FALSE);
}
