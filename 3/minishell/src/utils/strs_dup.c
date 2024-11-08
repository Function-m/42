/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:32:02 by suham             #+#    #+#             */
/*   Updated: 2024/01/21 23:41:09 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**strs_dup(char **src, t_memory **memory)
{
	char	**new;
	size_t	len;
	size_t	i;

	if (src == NULL)
		return (NULL);
	len = strs_len(src);
	new = do_calloc((len + 1) * sizeof(char *), memory);
	i = 0;
	while (i < len)
	{
		new[i] = str_dup(src[i], memory);
		i++;
	}
	new[len] = NULL;
	return (new);
}
