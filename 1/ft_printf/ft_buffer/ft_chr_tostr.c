/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_tostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:42:50 by suham             #+#    #+#             */
/*   Updated: 2023/06/10 22:23:08 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

int	ft_chr_tostr(char **new, char chr)
{
	if (ft_null_tostr(new, 1) == ERROR)
		return (ERROR);
	**new = chr;
	return (0);
}
