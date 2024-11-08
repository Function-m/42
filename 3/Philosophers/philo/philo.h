/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:40:12 by suham             #+#    #+#             */
/*   Updated: 2024/01/04 01:10:53 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

// General return value of functions.
# define SUCCESS	0
# define FAILURE	-1

// Boolean value.
# define FALSE		0
# define TRUE		1

// Philo program state.
# define START		0
# define STOP		1
# define END		2

typedef struct s_public_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal_count;
	ssize_t			base_time;
	int				*fork;
	pthread_mutex_t	*fork_mutex;
	int				philos_state;
	pthread_mutex_t	philos_state_mutex;
	pthread_mutex_t	print_mutex;
}	t_public_data;

typedef struct s_philo
{
	t_public_data	*public_data;
	pthread_t		thread_id;
	int				philo_id;
	int				overeating;
	int				meal_count;
	ssize_t			last_meal_time;
	pthread_mutex_t	meal_mutex;
	int				left_fork;
	int				right_fork;
}	t_philo;

// util_str.c
int		is_num(char *str);
size_t	to_num(char *str);
void	print_philo_log(t_philo *philo, char *philo_log);

// util_time.c
ssize_t	get_current_time(void);
void	sleep_for_ms(ssize_t ms);

// fork_handler.c
int		init_forks(t_philo *philo);
void	put_forks(t_philo *philo);
void	take_forks(t_philo *philo);

// philo_routine.c
int		get_philos_state(t_philo *philo);
void	set_philos_state(t_philo *philo, int value);
void	*philo_routine(void *arg);

// Main flow.
int		init_philo(t_philo **philo, int argc, char **argv);
int		run_philo(t_philo *philo);
void	observe_philo(t_philo *philo);

#endif
