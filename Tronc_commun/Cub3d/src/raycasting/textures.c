/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:43:20 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/23 06:57:45 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_strip_texture(t_cub *data, int x)
{
	float	strip;

	strip = 0;
	if (data->rays[x].wall_text == NO)
		strip = (data->rays[x].pos.x - (int)data->rays[x].pos.x);
	else if (data->rays[x].wall_text == SO)
		strip = (1 - (data->rays[x].pos.x - (int)data->rays[x].pos.x));
	else if (data->rays[x].wall_text == EA)
		strip = (1 - (data->rays[x].pos.y - (int)data->rays[x].pos.y));
	else if (data->rays[x].wall_text == WE)
		strip = (data->rays[x].pos.y - (int)data->rays[x].pos.y);
	return (strip * data->text[data->rays[x].wall_text].width);
}

void	render_strip_texture(t_cub *data, int x, int y, int height)
{
	float		ratio;
	int			max_height;
	t_points	text;

	ratio = (float)data->text[data->rays[x].wall_text].height / (float)height;
	max_height = data->mlx.screen_center + height / 2;
	text.x = get_strip_texture(data, x);
	text.y = 0;
	if (y < 0)
	{
		text.y += ratio * -y;
		y = 0;
	}
	if (max_height > WIN_HEIGHT - 1)
		max_height = WIN_HEIGHT - 1;
	while (y <= max_height)
	{
		my_mlx_pixel_put(&data->mlx, x, y,
			my_mlx_pixel_get(&data->text[data->rays[x].wall_text],
				(int)text.x, (int)text.y));
		if (text.y + ratio < data->text[data->rays[x].wall_text].height)
			text.y += ratio;
		y++;
	}
}

void	render_textures(t_cub *data)
{
	int	x;
	int	wall_top_px;

	x = 0;
	while (x < NUM_RAYS)
	{
		wall_top_px = (WIN_HEIGHT / 2) - (data->rays[x].wall_height / 2);
		if (data->rays[x].pos.x && data->rays[x].pos.y)
			render_strip_texture(data, x,
				wall_top_px, data->rays[x].wall_height);
		x++;
	}
}

void	render_colors(t_cub *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(&data->mlx, x, y, data->colors.ceiling);
			else
				my_mlx_pixel_put(&data->mlx, x, y, data->colors.floor);
			x++;
		}
		y++;
	}
}
