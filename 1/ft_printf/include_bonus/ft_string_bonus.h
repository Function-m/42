/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 06:05:10 by suham             #+#    #+#             */
/*   Updated: 2023/06/15 05:55:38 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_BONUS_H
# define FT_STRING_BONUS_H

# include <stdlib.h>

void	ft_memcpy(void *dst, void *src, size_t srcsize);
char	*ft_strchr(char *str, char chr);
size_t	ft_strlen(char *str);
size_t	ft_strlen_num(long long num, int base);
size_t	ft_strlen_unum(size_t unum, int base);

#endif