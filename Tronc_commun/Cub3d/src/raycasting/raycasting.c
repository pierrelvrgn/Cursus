/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:34:02 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/23 12:18:42 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	horz_intersection(t_cub *data, t_ray *ray)
{
	ray->a_tan = -1 / tan(ray->ray_angle);
	if (ray->ray_angle > PI)
	{
		ray->pos.y = (int)data->player.pos.y - 0.0001;
		ray->step.y = -1;
	}
	else
	{
		ray->pos.y = (int)data->player.pos.y + 1;
		ray->step.y = 1;
	}
	ray->pos.x = (data->player.pos.y - ray->pos.y)
		* ray->a_tan + data->player.pos.x;
	ray->step.x = -ray->step.y * ray->a_tan;
	while (ft_between(0, (int)ray->pos.x, data->map.length - 1)
		&& ft_between(0, (int)ray->pos.y, data->map.height - 1)
		&& data->map.map[(int)ray->pos.y][(int)ray->pos.x] != '1')
	{
		ray->pos.x += ray->step.x;
		ray->pos.y += ray->step.y;
	}
	ray->distance = distance_between_points(data->player.pos.x,
			data->player.pos.y, ray->pos.x, ray->pos.y);
}

void	vert_intersection(t_cub *data, t_ray *ray)
{
	ray->a_tan = -tan(ray->ray_angle);
	if (ray->ray_angle > PI / 2 && ray->ray_angle < 1.5 * PI)
	{
		ray->pos.x = (int)data->player.pos.x - 0.0001;
		ray->step.x = -1;
	}
	else
	{
		ray->pos.x = (int)data->player.pos.x + 1;
		ray->step.x = 1;
	}
	ray->pos.y = (data->player.pos.x - ray->pos.x)
		* ray->a_tan + data->player.pos.y;
	ray->step.y = -ray->step.x * ray->a_tan;
	while (ft_between(0, (int)ray->pos.x, data->map.length - 1)
		&& ft_between(0, (int)ray->pos.y, data->map.height - 1)
		&& data->map.map[(int)ray->pos.y][(int)ray->pos.x] != '1')
	{
		ray->pos.x += ray->step.x;
		ray->pos.y += ray->step.y;
	}
	ray->distance = distance_between_points(data->player.pos.x,
			data->player.pos.y, ray->pos.x, ray->pos.y);
}

void	cast_ray(t_cub *data, t_ray *ray, int strip_id)
{
	t_ray	horz_ray;
	t_ray	vert_ray;

	horz_ray = *ray;
	vert_ray = *ray;
	horz_intersection(data, &horz_ray);
	vert_intersection(data, &vert_ray);
	if (horz_ray.distance < vert_ray.distance)
	{
		*ray = horz_ray;
		if (ft_fbetween(0, ray->ray_angle, PI))
			ray->wall_text = NO;
		else
			ray->wall_text = SO;
	}
	else
	{
		*ray = vert_ray;
		if (ft_fbetween(PI / 2, ray->ray_angle, PI * 1.5))
			ray->wall_text = EA;
		else
			ray->wall_text = WE;
	}
	ray->distance *= cos(data->player.rot_angle - ray->ray_angle);
	ray->strip_id = strip_id;
}

void	cast_all_rays(t_cub *data)
{
	int		strip_id;

	strip_id = 0;
	data->rays[strip_id].ray_angle = data->player.rot_angle - FOV_ANGLE / 2;
	while (strip_id < NUM_RAYS)
	{
		normalize_angle(&data->rays[strip_id].ray_angle);
		cast_ray(data, &data->rays[strip_id], strip_id);
		if (!(ft_between(0, (int)data->rays[strip_id].pos.x,
					data->map.length - 1) && ft_between(0,
					(int)data->rays[strip_id].pos.y, data->map.height - 1)))
		{
			data->rays[strip_id].pos.x = 0;
			data->rays[strip_id].pos.y = 0;
		}
		data->rays[strip_id].wall_height = WIN_HEIGHT
			/ data->rays[strip_id].distance;
		strip_id++;
		data->rays[strip_id].ray_angle = data->rays[strip_id - 1].ray_angle
			+ FOV_ANGLE / NUM_RAYS;
	}
}
