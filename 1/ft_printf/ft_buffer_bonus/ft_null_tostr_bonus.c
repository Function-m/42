/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_tostr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:55 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer_bonus.h"

int	ft_null_tostr(char **new, size_t length)
{
	*new = malloc(length + 1);
	if (*new == NULL)
		return (ERROR);
	while (length != 0)
		*(*new + length--) = '\0';
	**new = '\0';
	return (0);
}
