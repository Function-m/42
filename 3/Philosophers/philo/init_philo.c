/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:11:51 by suham             #+#    #+#             */
/*   Updated: 2024/01/07 11:01:33 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_public_data(t_public_data **new_public_data, int argc, char **argv)
{
	*new_public_data = malloc(sizeof(t_public_data));
	if (*new_public_data == NULL)
		return (FAILURE);
	(*new_public_data)->num_of_philo = to_num(argv[1]);
	(*new_public_data)->time_to_die = to_num(argv[2]);
	(*new_public_data)->time_to_eat = to_num(argv[3]);
	(*new_public_data)->time_to_sleep = to_num(argv[4]);
	if (argc == 6)
		(*new_public_data)->max_meal_count = to_num(argv[5]);
	else
		(*new_public_data)->max_meal_count = -1;
	(*new_public_data)->philos_state = STOP;
	pthread_mutex_init(&(*new_public_data)->philos_state_mutex, NULL);
	pthread_mutex_init(&(*new_public_data)->print_mutex, NULL);
	return (SUCCESS);
}

int	init_philo_data(t_philo **philo, t_public_data *new_public_data)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * new_public_data->num_of_philo);
	if (*philo == NULL)
		return (FAILURE);
	i = 0;
	while (i < new_public_data->num_of_philo)
	{
		(*philo + i)->public_data = new_public_data;
		(*philo + i)->last_meal_time = 0;
		(*philo + i)->meal_count = 0;
		(*philo + i)->philo_id = i;
		(*philo + i)->overeating = FALSE;
		pthread_mutex_init(&(*philo + i)->meal_mutex, NULL);
		i++;
	}
	return (SUCCESS);
}

int	init_philo(t_philo **philo, int argc, char **argv)
{
	t_public_data	*new_public_data;

	if (init_public_data(&new_public_data, argc, argv) == FAILURE)
		return (FAILURE);
	if (init_philo_data(philo, new_public_data) == FAILURE)
		return (FAILURE);
	if (init_forks(*philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
