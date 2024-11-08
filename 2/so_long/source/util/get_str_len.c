/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:23:21 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 05:31:23 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ull	get_str_len(const char *str)
{
	t_ull	str_len;

	str_len = 0;
	while (str && *(str + str_len))
		++str_len;
	return (str_len);
}
