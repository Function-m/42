/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:32:16 by suham             #+#    #+#             */
/*   Updated: 2024/01/05 20:36:43 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_philos_state(t_philo *philo)
{
	int	philos_state;

	pthread_mutex_lock(&philo->public_data->philos_state_mutex);
	philos_state = philo->public_data->philos_state;
	pthread_mutex_unlock(&philo->public_data->philos_state_mutex);
	return (philos_state);
}

void	set_philos_state(t_philo *philo, int value)
{
	pthread_mutex_lock(&philo->public_data->philos_state_mutex);
	philo->public_data->philos_state = value;
	pthread_mutex_unlock(&philo->public_data->philos_state_mutex);
}

int	philo_eat(t_philo *philo)
{
	take_forks(philo);
	print_philo_log(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = \
				get_current_time() + philo->public_data->time_to_die;
	pthread_mutex_unlock(&philo->meal_mutex);
	sleep_for_ms(philo->public_data->time_to_eat);
	put_forks(philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	return (SUCCESS);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_philos_state(philo) == STOP)
		usleep(100);
	sleep_for_ms(
		(philo->public_data->time_to_eat / 2) * (philo->philo_id % 2));
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_lock(philo->public_data->fork_mutex + philo->left_fork);
		print_philo_log(philo, "has taken a fork");
	}
	while (get_philos_state(philo) != END)
	{
		if (philo->left_fork == philo->right_fork)
			continue ;
		philo_eat(philo);
		print_philo_log(philo, "is sleeping");
		sleep_for_ms(philo->public_data->time_to_sleep);
		print_philo_log(philo, "is thinking");
	}
	if (philo->left_fork == philo->right_fork)
		pthread_mutex_unlock(philo->public_data->fork_mutex + philo->left_fork);
	return (NULL);
}
