/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:11:12 by suham             #+#    #+#             */
/*   Updated: 2024/02/16 05:52:47 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "wrapper/wrapper.h"

char	*ft_read(char *file_name);
int		ft_strrcmp(char *s1, char *s2);
int		ft_strncmp(char *str_1, char *str_2, size_t n);
int		ft_strlen(char *s);
int		ft_isspace(char c);
char	*ft_strchrs(char *str, char *chrset);
size_t	ft_atoi(char *str);
char	*ft_strncpy(char *dst, const char *src, size_t n);
void	*ft_memset(void *dst, int chr, size_t len);

#endif
