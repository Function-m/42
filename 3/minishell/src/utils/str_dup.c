/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:32:02 by suham             #+#    #+#             */
/*   Updated: 2024/01/24 13:42:03 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_dup(char *src, t_memory **memory)
{
	size_t	src_len;
	char	*new;

	src_len = str_len(src) + 1;
	new = do_calloc(src_len, memory);
	str_cpy(new, src);
	return (new);
}
