/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:05:10 by suham             #+#    #+#             */
/*   Updated: 2023/06/17 09:57:17 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "ft_string_bonus.h"
# include "ft_buffer_bonus.h"

# define ERROR			-1
# define F_SHARP		0b1
# define F_PLUS			0b10
# define F_WHITE		0b100
# define F_SWAP			0b1000
# define F_ZERO			0b10000
# define F_PTR			0b100000
# define F_NEGATIVE		0b1000000
# define F_PRECISION	0b10000000

int	ft_printf(const char *str, ...);
int	_ftpf_read(t_lst **head, char *str, va_list *argp);
int	_ftpf_read_str(t_lst **head, char **str);
int	_ftpf_read_arg_one(t_lst *tail, char chr, va_list *argp);
int	_ftpf_read_arg_two(t_lst *tail, char chr, va_list *argp);
int	_ftpf_print(t_lst **head);
int	_ftpf_end(t_lst **head, va_list *argp, int return_value);

int	_ftpf_extra_read(t_lst *tail, char **str, size_t *exsize);
int	_ftpf_extra_apply(t_lst *tail, char chr, size_t *exsize);
int	_ftpf_apply_rmprefix(t_lst *tail);
int	_ftpf_apply_precision(t_lst *tail, char chr, size_t *exsize);
int	_ftpf_apply_addprefix(t_lst *tail, char chr);
int	_ftpf_apply_width(t_lst *tail, size_t *exsize);

#endif