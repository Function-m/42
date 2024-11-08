/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:44:35 by suham             #+#    #+#             */
/*   Updated: 2024/02/16 14:24:39 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPER_H
# define WRAPPER_H

# include <mlx.h>

// Used for file I/O operations like open, read, write, close.
# include <unistd.h>

// Used for file control operations like open.
# include <fcntl.h>

// Standard I/O functions like printf, perror.
# include <stdio.h>

// Standard library functions like malloc, free, exit.
# include <stdlib.h>

// String handling functions like strerror.
# include <string.h>

// memory_handler.c
void	*do_calloc(size_t size);
void	do_free(void *target);
void	do_free_all(void);

// io_controller.c
ssize_t	do_read(int fd, void *buf, size_t count);
ssize_t	do_write(int fd, void *buf, size_t count);

// file_manager.c
int		do_open(char *path, int flags);
void	do_close(int fd);
void	do_close_all(void);

// exit_routine.c
void	do_exit(int status);

// mlx extended.c
void	*do_mlx_init(void);
void	*do_mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*do_mlx_new_image(void *mlx_ptr, int width, int height);
void	*do_mlx_xpm_file_to_image(
			void *xvar, char *file, int *width, int *height);

#endif
