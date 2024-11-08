/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:32:02 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 07:04:42 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**strs_remove(char **strs, char *target, t_memory **memory)
{
	size_t	len;
	size_t	i;

	if (!target)
		return (strs);
	len = strs_len(strs);
	i = 0;
	while (i < len && strs[i] != target)
		i++;
	if (i == len)
		return (strs);
	do_free(strs[i], memory);
	while (i < len - 1)
	{
		strs[i] = strs[i + 1];
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
