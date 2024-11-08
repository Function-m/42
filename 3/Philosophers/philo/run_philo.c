/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:11:51 by suham             #+#    #+#             */
/*   Updated: 2024/01/05 19:19:18 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->public_data->num_of_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, philo_routine, philo + i);
		i++;
	}
	observe_philo(philo);
	i = 0;
	while (i < philo->public_data->num_of_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	return (SUCCESS);
}
