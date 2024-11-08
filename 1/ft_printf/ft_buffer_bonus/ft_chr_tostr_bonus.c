/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_tostr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/12 22:02:02 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer_bonus.h"

int	ft_chr_tostr(char **new, char chr)
{
	if (ft_null_tostr(new, 1) == ERROR)
		return (ERROR);
	**new = chr;
	return (0);
}
