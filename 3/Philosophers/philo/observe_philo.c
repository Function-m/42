/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:25:50 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 01:39:15 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_last_meal_time(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->public_data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].meal_mutex);
		philo[i].last_meal_time = \
			philo->public_data->base_time + philo->public_data->time_to_die;
		pthread_mutex_unlock(&philo[i].meal_mutex);
		i++;
	}
}

int	is_philos_alive(
	t_philo *philo, ssize_t current_time, int *total_overeating)
{
	int	i;

	i = 0;
	while (i < philo->public_data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].meal_mutex);
		if (current_time >= philo[i].last_meal_time)
		{
			pthread_mutex_unlock(&philo[i].meal_mutex);
			set_philos_state(philo, END);
			printf(
				"%ld %d died\n",
				current_time - philo->public_data->base_time, i);
			return (FALSE);
		}
		if (!philo[i].overeating && philo->public_data->max_meal_count != -1
			&& philo[i].meal_count >= philo->public_data->max_meal_count)
		{
			philo[i].overeating = TRUE;
			(*total_overeating)++;
		}
		pthread_mutex_unlock(&philo[i].meal_mutex);
		i++;
	}
	return (TRUE);
}

void	observe_philo(t_philo *philo)
{
	int		total_overeating;
	ssize_t	current_time;

	total_overeating = 0;
	philo->public_data->base_time = get_current_time();
	init_last_meal_time(philo);
	set_philos_state(philo, START);
	while (TRUE)
	{
		current_time = get_current_time();
		if (is_philos_alive(philo, current_time, &total_overeating) == FALSE)
			return ;
		if (total_overeating == philo->public_data->num_of_philo)
		{
			set_philos_state(philo, END);
			return ;
		}
		usleep(100);
	}
}
