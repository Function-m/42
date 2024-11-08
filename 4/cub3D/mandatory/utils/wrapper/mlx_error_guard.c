/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_error_guard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:58:21 by youngjin          #+#    #+#             */
/*   Updated: 2024/02/16 00:12:15 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	*do_mlx_init(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		perror("Error\nmlx_init");
		do_exit(EXIT_FAILURE);
	}
	return (mlx);
}

void	*do_mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	void	*win;

	win = mlx_new_window(mlx_ptr, size_x, size_y, title);
	if (win == NULL)
	{
		perror("Error\nmlx_new_window");
		do_exit(EXIT_FAILURE);
	}
	return (win);
}

void	*do_mlx_new_image(void *mlx_ptr, int width, int height)
{
	void	*img;

	img = mlx_new_image(mlx_ptr, width, height);
	if (img == NULL)
	{
		perror("Error\nmlx_new_image");
		do_exit(EXIT_FAILURE);
	}
	return (img);
}

void	*do_mlx_xpm_file_to_image(
	void *xvar, char *file, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(xvar, file, width, height);
	if (img == NULL)
	{
		perror("Error\nmlx_xpm_file_to_image");
		do_exit(EXIT_FAILURE);
	}
	return (img);
}
