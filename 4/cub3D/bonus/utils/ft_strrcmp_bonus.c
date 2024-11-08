/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:11:29 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	ft_strrcmp(char	*s1, char *s2)
{
	char	*es1;
	char	*es2;

	if (s1 == NULL)
		return (1);
	es1 = s1 + ft_strlen(s1);
	es2 = s2 + ft_strlen(s2);
	while (es1 >= s1 && es2 >= s2)
	{
		if (*es1 != *es2)
			return (1);
		es1--;
		es2--;
	}
	return (0);
}
