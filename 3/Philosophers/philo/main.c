/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:29:41 by suham             #+#    #+#             */
/*   Updated: 2024/01/07 11:03:01 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_out_range(const char *str)
{
	int			i;
	int			length;
	const int	max_int_len = 10;
	const char	max_int_str[] = "2147483647";

	i = 0;
	while (str[i] != '\0')
		i++;
	length = i;
	if (length > max_int_len)
		return (TRUE);
	if (length == max_int_len)
	{
		i = 0;
		while (i < length)
		{
			if (str[i] > max_int_str[i])
				return (TRUE);
			if (str[i] < max_int_str[i])
				break ;
			i++;
		}
	}
	return (FALSE);
}

int	validate_argc_n_argv(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (FALSE);
	i = 1;
	while (i < argc)
	{
		if (is_num(argv[i]) == FALSE)
			return (FALSE);
		if (is_out_range(argv[i]) == TRUE)
			return (FALSE);
		if (argv[i][0] == '0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	cleanup_all(t_philo *philo, int exit_status)
{
	int	i;

	i = 0;
	while (i < philo->public_data->num_of_philo)
	{
		pthread_mutex_destroy(&philo[i].meal_mutex);
		pthread_mutex_destroy(philo[i].public_data->fork_mutex);
		i++;
	}
	pthread_mutex_destroy(&philo->public_data->philos_state_mutex);
	pthread_mutex_destroy(&philo->public_data->print_mutex);
	free(philo->public_data->fork);
	free(philo->public_data->fork_mutex);
	free(philo->public_data);
	free(philo);
	return (exit_status);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (validate_argc_n_argv(argc, argv) == FALSE)
		return (EXIT_FAILURE);
	if (init_philo(&philo, argc, argv) == FAILURE)
		return (EXIT_FAILURE);
	if (run_philo(philo) == FAILURE)
		return (cleanup_all(philo, EXIT_FAILURE));
	cleanup_all(philo, 0);
}
