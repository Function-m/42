/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 06:33:36 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

char	*ft_strchrs(char *str, char *chrset)
{
	char	*current_chr;

	current_chr = chrset;
	if (!str || !chrset)
		return (NULL);
	while (*str != '\0')
	{
		current_chr = chrset;
		while (*current_chr != '\0')
		{
			if (*str == *current_chr)
				return (str);
			current_chr++;
		}
		str++;
	}
	return (str);
}
