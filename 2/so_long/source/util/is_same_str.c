/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:23:21 by suham             #+#    #+#             */
/*   Updated: 2023/11/20 21:56:15 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_same_str(const char *one, const char *two)
{
	while (*one && *two)
	{
		if (*one++ != *two++)
			return (FALSE);
	}
	if (*one == *two)
		return (TRUE);
	else
		return (FALSE);
}
