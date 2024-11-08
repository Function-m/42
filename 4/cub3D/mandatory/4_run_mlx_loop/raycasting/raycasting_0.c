/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:35:54 by suham             #+#    #+#             */
/*   Updated: 2024/02/17 19:46:55 by suham            ###   ########seoul.kr  */
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

void	calculate_texture(t_cub3d *cub3d, t_ray_vars *ray);
void	calculate_wall_drawing_positions(t_ray_vars *ray);
void	render_wall_texture(t_cub3d *cub3d, t_ray_vars *ray);

void	init_ray_vars_info(t_cub3d *cub3d, t_ray_vars *ray)
{
	ray->camera_x = 2 * ray->x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x \
		= cub3d->player.dir.x + cub3d->player.plane.x * ray->camera_x;
	ray->ray_dir_y \
		= cub3d->player.dir.y + cub3d->player.plane.y * ray->camera_x;
	ray->map_x = (int)cub3d->player.pos.x;
	ray->map_y = (int)cub3d->player.pos.y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	calculate_step_and_sidedist(t_cub3d *cub3d, t_ray_vars *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x \
			= (cub3d->player.pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x \
			= (ray->map_x + 1.0 - cub3d->player.pos.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y \
			= (cub3d->player.pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y \
			= (ray->map_y + 1.0 - cub3d->player.pos.y) * ray->delta_dist_y;
	}
}

void	calculate_perp_wall_dist(t_cub3d *cub3d, t_ray_vars *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist \
			= (ray->map_x - cub3d->player.pos.x + (1 - ray->step_x) / 2) \
				/ ray->ray_dir_x;
	else
		ray->perp_wall_dist \
			= (ray->map_y - cub3d->player.pos.y + (1 - ray->step_y) / 2) \
				/ ray->ray_dir_y;
}

void	perform_dda(t_cub3d *cub3d, t_ray_vars *ray)
{
	while (true)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (cub3d->map.data[ray->map_y][ray->map_x] == '1'
			|| cub3d->map.data[ray->map_y][ray->map_x] == '2')
			break ;
	}
}

void	raycasting(t_cub3d *cub3d)
{
	t_ray_vars	ray;

	ray.x = 0;
	while (ray.x < WIN_WIDTH)
	{
		init_ray_vars_info(cub3d, &ray);
		calculate_step_and_sidedist(cub3d, &ray);
		perform_dda(cub3d, &ray);
		calculate_perp_wall_dist(cub3d, &ray);
		calculate_wall_drawing_positions(&ray);
		calculate_texture(cub3d, &ray);
		render_wall_texture(cub3d, &ray);
		ray.x++;
	}
}
