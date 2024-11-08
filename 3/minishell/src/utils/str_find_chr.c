/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:26:57 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 22:26:20 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_find_chr(char *str, char *chrset)
{
	char	*ptr;

	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		ptr = chrset;
		while (*ptr != '\0')
		{
			if (*str == *ptr)
				return (str);
			ptr++;
		}
		str++;
	}
	return (str);
}
