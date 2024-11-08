/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:16:24 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 13:29:36 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

//	If error, the message that handle_exit prints
# define ERR_MESSAGE "Error\n"

//	Status of hande_exit
# define ERR_MALLOC_FAILED			-1
# define ERR_INVALID_ARGUMENT		-2
# define ERR_SORT_FAILED			-3
# define ERR_WRITE_FUNCTION_FAILS	-4

//	Boolean
# define TRUE	1
# define FALSE	0

//	Replaces those in the standard library
# define _NULL			((void *)0)
# define _STDOUT_FILENO	1
# define _STDERR_FILENO	2
# define _INT_MAX		2147483647
# define _INT_MIN		-2147483648

typedef long long			t_ll;
typedef unsigned long long	t_ull;

void	handle_exit(int status);
t_ll	handle_write(int fd, const char *str, t_ull size);
void	*handle_malloc(t_ull size, t_ull type_size);
t_ull	get_strlen(const char *str);
int		get_numlen(int number);
int		is_numeric(int c);
int		convert_str_to_int(const char *str);
char	**convert_to_split_str(char *str, int delimiter);

#endif
