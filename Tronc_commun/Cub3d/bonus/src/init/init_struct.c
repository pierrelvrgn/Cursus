/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:35:41 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/23 09:22:56 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_cub *data)
{
	if (data->map.p_facing == 'N')
		data->player.rot_angle = 1.5 * PI;
	else if (data->map.p_facing == 'S')
		data->player.rot_angle = PI / 2;
	else if (data->map.p_facing == 'E')
		data->player.rot_angle = 0;
	else if (data->map.p_facing == 'W')
		data->player.rot_angle = PI;
	data->player.step.x = cos(data->player.rot_angle) / 10;
	data->player.step.y = sin(data->player.rot_angle) / 10;
	data->player.walk_direction = 0;
}

void	init_controls(t_cub *data)
{
	data->keys.w = 0;
	data->keys.a = 0;
	data->keys.d = 0;
	data->keys.s = 0;
	data->keys.l_arrow = 0;
	data->keys.r_arrow = 0;
	data->keys.esc = 0;
}

void	init_params(t_cub *data)
{
	data->mlx.mlx_win = NULL;
	data->mlx.screen_center = WIN_HEIGHT / 2;
	data->colors.text[NO] = NULL;
	data->colors.text[SO] = NULL;
	data->colors.text[EA] = NULL;
	data->colors.text[WE] = NULL;
	data->colors.ceiling = -1;
	data->colors.floor = -1;
	data->mlx.img = 0;
	data->text[0].img = NULL;
	data->text[1].img = NULL;
	data->text[2].img = NULL;
	data->text[3].img = NULL;
}
