/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:15:02 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:01:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_bonus.h"

char	*ft_strchr(char *str, char chr)
{
	while (*str != '\0' && *str != chr)
		++str;
	return (str);
}
