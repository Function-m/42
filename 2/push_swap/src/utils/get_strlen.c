/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:19:26 by suham             #+#    #+#             */
/*   Updated: 2023/10/25 00:53:45 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_ull	get_strlen(const char *str)
{
	t_ull	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}