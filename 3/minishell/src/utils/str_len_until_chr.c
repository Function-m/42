/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len_until_chr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:53:28 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 22:28:13 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	str_len_until_chr(char *str, char chr)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len])
	{
		if (str[str_len] == chr)
			return (str_len + 1);
		str_len++;
	}
	return (str_len);
}
