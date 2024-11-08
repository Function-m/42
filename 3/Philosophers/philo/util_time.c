/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:34:12 by suham             #+#    #+#             */
/*   Updated: 2024/01/05 11:56:22 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The following function is based on milisodes. */

#include "philo.h"

void	sleep_for_ms(ssize_t ms)
{
	ssize_t	end_time;

	end_time = get_current_time() + ms;
	while (TRUE)
	{
		if (get_current_time() >= end_time)
			break ;
		usleep(100);
	}
}

ssize_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
