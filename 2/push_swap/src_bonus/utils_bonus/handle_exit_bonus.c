/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:28:45 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 12:11:11 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	handle_exit(int status)
{
	if (status != 0)
		handle_write(_STDERR_FILENO, ERR_MESSAGE, sizeof(ERR_MESSAGE));
	exit(status);
}
