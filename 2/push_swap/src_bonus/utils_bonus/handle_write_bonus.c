/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:51:42 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 12:11:16 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_ll	handle_write(int fd, const char *str, t_ull size)
{
	t_ll	return_value;

	return_value = write(fd, str, size);
	if (return_value == -1)
		handle_exit(ERR_WRITE_FUNCTION_FAILS);
	return (return_value);
}
