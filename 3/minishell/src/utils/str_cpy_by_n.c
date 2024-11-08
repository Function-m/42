/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cpy_by_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:32:02 by suham             #+#    #+#             */
/*   Updated: 2024/01/21 21:54:14 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	str_cpy_by_n(char *dst, char *src, size_t n)
{
	size_t	src_len;
	size_t	i;

	if (dst == NULL || src == NULL)
		return ;
	src_len = str_len(src);
	if ((src < dst) && (dst < src + src_len))
	{
		i = (n < src_len) * n + (n >= src_len) * src_len - 1;
		while (i >= 0)
		{
			dst[i] = src[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
}
