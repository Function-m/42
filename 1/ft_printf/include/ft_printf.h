/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:05:10 by suham             #+#    #+#             */
/*   Updated: 2023/06/17 09:56:13 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "ft_string.h"
# include "ft_buffer.h"

# define ERROR -1

int	ft_printf(const char *str, ...);
int	_ftpf_read(t_lst **head, char *str, va_list *argp);
int	_ftpf_read_str(t_lst **head, char **str);
int	_ftpf_read_arg_one(t_lst *tail, char chr, va_list *argp);
int	_ftpf_read_arg_two(t_lst *tail, char chr, va_list *argp);
int	_ftpf_print(t_lst **head);
int	_ftpf_end(t_lst **head, va_list *argp, int return_value);

#endif