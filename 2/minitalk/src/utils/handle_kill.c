/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_kill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:50:45 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 16:24:13 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handle_kill(long long pid, int sig)
{
	if (kill(pid, sig) != 0)
		handle_exit(ERR_KILL);
	usleep(200);
}
