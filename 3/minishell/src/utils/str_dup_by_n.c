/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup_by_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:28:36 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 22:29:27 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_dup_by_n(char *str, size_t n, t_memory **memory)
{
	char	*new_str;

	new_str = do_calloc(n + 1, memory);
	str_cpy_by_n(new_str, str, n);
	new_str[n] = '\0';
	return (new_str);
}
