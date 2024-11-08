/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:54:23 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 14:13:07 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Preprocessors */
# define TRUE 1
# define FALSE 0

# define _NULL ((void *)0)

# define _STDOUT_FILENO 1
# define _STDERR_FILENO 2

# define ERR_ARGUMENT -1
# define ERR_MALLOC -2
# define ERR_WRITE -3
# define ERR_KILL -4

/* External libraries */
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

/* Functions */
void		handle_exit(int status);
void		handle_kill(long long pid, int sig);
char		*num_to_str(long long num);
long long	str_to_num(const char *str);
long long	handle_write(int fd, const char *str);

#endif
