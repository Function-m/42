/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:57:40 by suham             #+#    #+#             */
/*   Updated: 2024/01/05 18:37:57 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_num(char *str)
{
	if (str == NULL || *str == '\0')
		return (FALSE);
	if (str[0] == '0' && str[1] != '\0')
		return (FALSE);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

size_t	to_num(char *str)
{
	size_t	num;
	int		i;

	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

void	print_philo_log(t_philo *philo, char *philo_log)
{
	ssize_t	current_time;

	pthread_mutex_lock(&philo->public_data->print_mutex);
	current_time = get_current_time() - philo->public_data->base_time;
	if (get_philos_state(philo) != END)
		printf("%ld %d %s\n", current_time, philo->philo_id + 1, philo_log);
	pthread_mutex_unlock(&philo->public_data->print_mutex);
}
