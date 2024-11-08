/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:18:07 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 00:55:52 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

typedef struct s_ray_vars
{
	ssize_t	x;
	ssize_t	y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	double	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		color;
	int		tex_offset;
	double	step;
	double	tex_pos;
	t_img	wall_tex;
}	t_ray_vars;

void	draw(t_cub3d *cub3d, size_t x, size_t y, int rgb_color);

void	calculate_texture(t_cub3d *cub3d, t_ray_vars *ray)
{
	static int	time = 0;
	static int	door_idx = 0;

	if (time++ == 10000)
	{
		time = 0;
		if (++door_idx > 2)
			door_idx = 0;
	}
	if (cub3d->map.data[ray->map_y][ray->map_x] == '2')
		ray->wall_tex = cub3d->texture.door[door_idx];
	else if (ray->side == 0)
	{
		if (ray->step_x > 0)
			ray->wall_tex = cub3d->texture.west;
		else
			ray->wall_tex = cub3d->texture.east;
	}
	else
	{
		if (ray->step_y > 0)
			ray->wall_tex = cub3d->texture.south;
		else
			ray->wall_tex = cub3d->texture.north;
	}	
}

void	calculate_wall_drawing_positions(t_ray_vars *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = (int)fmax(-ray->line_height / 2 + WIN_HEIGHT / 2, 0);
	ray->draw_end = (int)fmin(ray->line_height / 2 + \
	WIN_HEIGHT / 2, WIN_HEIGHT - 1);
}

void	draw_wall_texture(t_cub3d *cub3d, t_ray_vars *ray)
{
	int	bpp;
	int	tex_x;
	int	tex_y;
	int	color;

	bpp = ray->wall_tex.bits_per_pixel / 8;
	tex_x = fmin(ray->tex_x, ray->wall_tex.width - 1);
	ray->y = ray->draw_start;
	while (ray->y < ray->draw_end)
	{
		tex_y = (int)(ray->tex_pos) % ray->wall_tex.height;
		ray->tex_pos += ray->step;
		color = *(int *)(ray->wall_tex.data \
			+ tex_y * ray->wall_tex.line_length + tex_x * bpp);
		draw(cub3d, ray->x, ray->y, color);
		ray->y++;
	}
}

void	render_wall_texture(t_cub3d *cub3d, t_ray_vars *ray)
{
	if (ray->side == 0)
		ray->wall_x \
			= cub3d->player.pos.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x \
			= cub3d->player.pos.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)(ray->wall_tex.width));
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = ray->wall_tex.width - ray->tex_x - 1;
	ray->step = 1.0 * ray->wall_tex.height / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2 \
		+ ray->line_height / 2) * ray->step;
	draw_wall_texture(cub3d, ray);
}
