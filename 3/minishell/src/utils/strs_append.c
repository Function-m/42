/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:32:02 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 22:28:31 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**strs_append(char **strs, char *new_str, t_memory **memory)
{
	size_t	len;
	char	**new_strs;
	size_t	i;

	len = strs_len(strs);
	new_strs = do_calloc(sizeof(char *) * (len + 2), memory);
	i = 0;
	while (i < len)
	{
		new_strs[i] = strs[i];
		i++;
	}
	new_strs[len] = new_str;
	new_strs[len + 1] = NULL;
	do_free(strs, memory);
	return (new_strs);
}
