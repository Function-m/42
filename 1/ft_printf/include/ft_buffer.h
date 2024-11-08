/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:05:10 by suham             #+#    #+#             */
/*   Updated: 2023/06/17 22:36:36 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include <stdlib.h>
# include "ft_string.h"

# define ERROR -1
# define DIGIT "0123456789abcdef0123456789ABCDEF"

typedef struct s_lst
{
	void			*content;
	size_t			size;
	size_t			flag;
	struct s_lst	*next;
}	t_lst;

int		ft_bufjoin(void **dst, size_t dstsize, void **src, size_t srcsize);

int		ft_null_tostr(char **new, size_t length);
int		ft_chr_tostr(char **new, char chr);
int		ft_str_tostr(char **new, char *str, size_t length);
int		ft_unum_tostr(char **new, size_t unum, int base, int upper);
int		ft_num_tostr(char **new, long num, int base, int upper);

t_lst	*ft_lsttail(t_lst *head);
int		ft_lstnew(t_lst **new);
int		ft_lstadd(t_lst **head, void *content, size_t size, size_t flag);
int		ft_lstloop(t_lst *head, int (*usef)(t_lst *));
int		ft_lstcombine(t_lst **head);

#endif