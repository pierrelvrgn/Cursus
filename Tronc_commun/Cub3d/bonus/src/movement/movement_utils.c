/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:55:21 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/24 14:01:35 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_has_wall_at(t_cub *data, float x, float y)
{
	int	map_grid_x;
	int	map_grid_y;

	if (x < 0 || x > data->map.length || y < 0 || y > data->map.height)
		return (1);
	map_grid_x = x;
	map_grid_y = y;
	if (data->map.map[map_grid_y][map_grid_x] == '1')
		return (1);
	else
		return (0);
}

void	use_mouse(t_cub *data)
{
	int			x;
	int			y;

	mlx_mouse_get_pos(data->mlx.mlx_win, &x, &y);
	if (x > (WIN_WIDTH * 0.5))
	{
		data->player.rot_angle += 0.06;
		normalize_angle(&data->player.rot_angle);
	}
	else if (x < (WIN_WIDTH * 0.5))
	{
		data->player.rot_angle -= 0.06;
		normalize_angle(&data->player.rot_angle);
	}
	mlx_mouse_move(data->mlx.mlx_win, WIN_WIDTH * 0.5, WIN_HEIGHT * 0.5);
}
