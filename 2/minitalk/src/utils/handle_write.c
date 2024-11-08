/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:44:31 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 17:16:32 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long long	handle_write(int fd, const char *str)
{
	long long	str_len;
	long long	result;

	str_len = 0;
	while (str[str_len] != '\0')
		++ str_len;
	result = write(fd, str, str_len);
	if (result == -1)
		handle_exit(ERR_WRITE);
	return (result);
}
