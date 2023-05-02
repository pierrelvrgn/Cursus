/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:35:48 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/23 13:08:11 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_player(int player, t_cub *data, int line, int column)
{
	if (data->map.map[line][column] == 'S'
		|| data->map.map[line][column]
		== 'W' || data->map.map[line][column] == 'N'
		|| data->map.map[line][column] == 'E')
	{
		data->map.p_facing = data->map.map[line][column];
		data->player.pos.y = line + 0.5;
		data->player.pos.x = column + 0.5;
		player++;
	}
	return (player);
}

void	check_player(t_cub *data)
{
	int	line;
	int	column;
	int	player;

	line = 0;
	player = 0;
	while (data->map.map[line])
	{
		column = 0;
		while (data->map.map[line][column])
		{
			player = count_player(player, data, line, column);
			column++;
		}
		line++;
	}
	if (player != 1)
		ft_exit(1, "MAP_PLAYER", data);
}

static void	check_space(t_cub *data, char **map, int line, int column)
{
	while (map[line] && map[line][column] && (map[line][column] == ' '
			|| map[line][column] == '\t'))
	{
		if (line > 1)
			check_line_before(data, map, line, column);
		if (column > 1)
			check_column_before(data, map, line, column);
		if (line < data->map.height)
			check_next_line(data, map, line, column);
		if (column < data->map.length)
			check_next_column(data, map, line, column);
		column++;
	}
	if (!map[line] || !map[line][column] || (map[line] && map[line][column]
		&& (map[line][column] == '1' || map[line][column] == '\n'
		|| map[line][column] == '\r')))
		return ;
	else
		ft_exit(1, "MAP_WALL", data);
}

static void	check_end_of_line_parsing(t_cub *data, char **map, int l, int c)
{
	if (c > 1)
	{
		c--;
		if (map[l] && map[l][c])
			if (!(map[l][c] == '1' || map[l][c] == ' ' || map[l][c] == '\t'))
				ft_exit(1, "MAP_WALL_E", data);
	}
	c = 0;
	if (l == 0 || l == data->map.height - 1)
	{
		while (map[l][c])
		{
			if (!(map[l][c] == '1' || map[l][c] == ' ' || map[l][c] == '\t'))
				ft_exit(1, "BAD_MAP", data);
			c++;
		}
	}
	else if (map[l][c])
	{
		while (map[l][c] && (map[l][c] == ' ' || map[l][c] == '\t'))
			c++;
		if (map[l][c] != '1')
			ft_exit(1, "MAP_WALL", data);
	}
}

void	check_map_wall(t_cub *data)
{
	int	line;
	int	column;

	line = 0;
	while (data->map.map[line])
	{
		column = 0;
		while (data->map.map[line][column])
		{
			if (data->map.map[line] && data->map.map[line][column]
				&& (data->map.map[line][column]
				== ' ' || data->map.map[line][column] == '\t'))
				check_space(data, data->map.map, line, column);
			column++;
		}
		check_end_of_line_parsing(data, data->map.map, line, column);
		line++;
	}
}
