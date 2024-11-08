/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:23:17 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 17:19:35 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	is_same_str(const char *one, const char *two)
{
	while (*one != '\0' && *two != '\0')
	{
		if (*one != *two)
			return (FALSE);
		++one;
		++two;
	}
	if (*one != '\0' || *two != '\0')
		return (FALSE);
	return (TRUE);
}
