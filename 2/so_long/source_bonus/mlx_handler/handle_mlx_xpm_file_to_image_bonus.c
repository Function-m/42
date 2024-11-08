/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx_xpm_file_to_image_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:51:22 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*handle_mlx_xpm_file_to_image(t_data *data, char *xpm_path)
{
	void	*img_ptr;
	int		temp;

	img_ptr = mlx_xpm_file_to_image(data->mlx.ptr, xpm_path,
			&temp, &temp);
	if (!img_ptr)
		handle_exit(FAILURE, "'mlx_xpm_file_to_image' function failed.\n");
	return (img_ptr);
}
