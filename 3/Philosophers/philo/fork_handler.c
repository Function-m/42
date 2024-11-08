/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:15:22 by suham             #+#    #+#             */
/*   Updated: 2024/01/05 11:56:11 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->public_data->fork_mutex + philo->left_fork);
	print_philo_log(philo, "has taken a fork");
	pthread_mutex_lock(philo->public_data->fork_mutex + philo->right_fork);
	print_philo_log(philo, "has taken a fork");
	philo->public_data->fork[philo->left_fork] = TRUE;
	philo->public_data->fork[philo->right_fork] = TRUE;
}

void	put_forks(t_philo *philo)
{
	philo->public_data->fork[philo->left_fork] = FALSE;
	philo->public_data->fork[philo->right_fork] = FALSE;
	pthread_mutex_unlock(philo->public_data->fork_mutex + philo->left_fork);
	pthread_mutex_unlock(philo->public_data->fork_mutex + philo->right_fork);
}

static int	create_forks(t_public_data *public_data)
{
	int	i;

	public_data->fork = malloc(sizeof(int) * public_data->num_of_philo);
	if (public_data->fork == NULL)
		return (FAILURE);
	public_data->fork_mutex = malloc(
			sizeof(pthread_mutex_t) * public_data->num_of_philo);
	if (public_data->fork_mutex == NULL)
	{
		free(public_data->fork);
		return (FAILURE);
	}
	i = 0;
	while (i < public_data->num_of_philo)
	{
		public_data->fork[i] = FALSE;
		pthread_mutex_init(&public_data->fork_mutex[i], NULL);
		i++;
	}
	return (SUCCESS);
}

static void	position_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->public_data->num_of_philo)
	{
		philo[i].left_fork = i;
		if (i == philo->public_data->num_of_philo - 1)
			philo[i].right_fork = 0;
		else
			philo[i].right_fork = i + 1;
		i++;
	}
}

int	init_forks(t_philo *philo)
{
	if (create_forks(philo->public_data) == FAILURE)
		return (FAILURE);
	position_forks(philo);
	return (SUCCESS);
}
