/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:31:46 by suham             #+#    #+#             */
/*   Updated: 2024/01/21 23:40:05 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	str_len(char *str)
{
	char	*ptr;

	if (str == NULL)
		return (0);
	ptr = str;
	while (*ptr != '\0')
		ptr++;
	return (ptr - str);
}
