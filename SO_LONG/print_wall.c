/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:09:08 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/18 18:53:59 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tree(t_vars *vars, void *img)
{
	int		l;
	int		c;

	c = 0;
	l = 0;
	while (l < vars->line)
	{
		while (c < vars->col)
		{
			if (vars->map[l][c] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img,
					(c * 100), (l * 100));
			c++;
		}
		c = 0;
		l++;
	}
	mlx_destroy_image(vars->mlx, img);
}

void	print_blue_orb(t_vars *vars, void *img)
{
	int	i;

	i = 0;
	while (i < vars->initial_collectible)
	{
		if (vars->get_collectible[i][0] != 0
			&& vars->get_collectible[i][1] != 0)
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, img,
				vars->get_collectible[i][0], vars->get_collectible[i][1]);
		i++;
	}
	mlx_destroy_image(vars->mlx, img);
}

void	print_character(t_vars *vars, void *img)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, img);
}

void	print_chest(t_vars *vars, void *img)
{
	int		l;
	int		c;

	l = 0;
	while (l < vars->line)
	{
		c = 0;
		while (c < vars->col)
		{
			if (vars->map[l][c] == 'E')
			{
				vars->x_chest = (c * 100);
				vars->y_chest = (l * 100);
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img,
					(c * 100), (l * 100));
			}
			c++;
		}
		l++;
	}
	mlx_destroy_image(vars->mlx, img);
}
