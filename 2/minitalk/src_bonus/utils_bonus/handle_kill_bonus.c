/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_kill_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:50:45 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 17:06:18 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	handle_kill(long long pid, int sig)
{
	if (kill(pid, sig) != 0)
		handle_exit(ERR_KILL);
	usleep(200);
}
