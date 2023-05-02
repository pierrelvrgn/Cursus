/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:38:16 by plavergn          #+#    #+#             */
/*   Updated: 2022/12/02 08:32:25 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_cub *data)
{
	t_points	new_pos;

	data->player.walk_direction = +1;
	new_pos.y = data->player.pos.y + (data->player.step.y
			* data->player.walk_direction) * 3;
	new_pos.x = data->player.pos.x + (data->player.step.x
			* data->player.walk_direction) * 3;
	if (!map_has_wall_at(data, new_pos.x, new_pos.y))
	{
		data->player.pos.y = new_pos.y;
		data->player.pos.x = new_pos.x;
	}
}

void	move_backward(t_cub *data)
{
	t_points	new_pos;

	data->player.walk_direction = -1;
	new_pos.x = data->player.pos.x + (data->player.step.x
			* data->player.walk_direction) * 3;
	new_pos.y = data->player.pos.y + (data->player.step.y
			* data->player.walk_direction) * 3;
	if (!map_has_wall_at(data, new_pos.x, new_pos.y))
	{
		data->player.pos.y = new_pos.y;
		data->player.pos.x = new_pos.x;
	}
}

void	left_move(t_cub *data)
{
	t_points	new_pos;

	data->player.walk_direction = +1;
	new_pos.y = data->player.pos.y - (data->player.step.x
			* data->player.walk_direction) * 3;
	new_pos.x = data->player.pos.x + (data->player.step.y
			* data->player.walk_direction) * 3;
	if (!map_has_wall_at(data, new_pos.x, new_pos.y))
	{
		data->player.pos.y = new_pos.y;
		data->player.pos.x = new_pos.x;
	}
}

void	right_move(t_cub *data)
{
	t_points	new_pos;

	data->player.walk_direction = -1;
	new_pos.y = data->player.pos.y - (data->player.step.x
			* data->player.walk_direction) * 3;
	new_pos.x = data->player.pos.x + (data->player.step.y
			* data->player.walk_direction) * 3;
	if (!map_has_wall_at(data, new_pos.x, new_pos.y))
	{
		data->player.pos.y = new_pos.y;
		data->player.pos.x = new_pos.x;
	}
}

void	check_moves(t_cub *data)
{
	if (data->keys.l_arrow)
		data->player.rot_angle -= 0.04;
	if (data->keys.r_arrow)
		data->player.rot_angle += 0.04;
	if (data->keys.w)
		move_forward(data);
	if (data->keys.s)
		move_backward(data);
	if (data->keys.a)
		left_move(data);
	if (data->keys.d)
		right_move(data);
	normalize_angle(&data->player.rot_angle);
	data->player.step.x = cos(data->player.rot_angle) / 10;
	data->player.step.y = sin(data->player.rot_angle) / 10;
}
