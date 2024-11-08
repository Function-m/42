/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_main_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:31:23 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 00:32:39 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	validate_main_arg(int argc, char *argv)
{
	if (argc != 2 || ft_strrcmp(argv, ".cub"))
	{
		write(2, ERRMSG_ARGUMENT, sizeof(ERRMSG_ARGUMENT) - 1);
		do_exit(EXIT_FAILURE);
	}
}
