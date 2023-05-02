/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:43:46 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/23 09:42:43 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_line_before(t_cub *data, char **map, int line, int column)
{
	if (map[line - 1] && map[line - 1][column] && !(map[line - 1][column]
		== '1' || map[line - 1][column] == ' ' || map[line - 1][column]
		== '\t'))
		ft_exit(1, "MAP_WALL", data);
}

void	check_column_before(t_cub *data, char **map, int line, int column)
{
	if (map[line] && map[line][column - 1]
		&& !(map[line][column - 1] == '1' || map[line][column - 1]
		== ' ' || map[line][column - 1] == '\t'))
		ft_exit(1, "MAP_WALL", data);
}

void	check_next_line(t_cub *data, char **map, int line, int column)
{
	if (map[line + 1] && map[line + 1][column] && !(map[line + 1][column]
		== '1' || map[line + 1][column] == ' ' || map[line + 1][column]
		== '\t'))
		ft_exit(1, "MAP_WALL", data);
}

void	check_next_column(t_cub *data, char **map, int line, int column)
{
	if (map[line] && map[line][column + 1]
		&& !(map[line][column + 1] == '1' || map[line][column + 1]
		== ' ' || map[line][column + 1] == '\t'))
		ft_exit(1, "MAP_WALL", data);
}
