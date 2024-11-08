/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:02:42 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 22:29:34 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_join(char *dst, char *src, size_t src_len, t_memory **memory)
{
	size_t	dst_len;
	char	*new;

	if (!src || !src_len)
		return (dst);
	if (!dst)
		return (str_dup_by_n(src, src_len, memory));
	dst_len = str_len(dst);
	new = do_calloc(dst_len + src_len + 1, memory);
	str_cpy_by_n(new, dst, dst_len);
	str_cpy_by_n(new + dst_len, src, src_len);
	new[dst_len + src_len] = '\0';
	do_free(dst, memory);
	return (new);
}
