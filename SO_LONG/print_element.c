/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:16:01 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/18 11:50:59 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_tree(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 115;
	test[1] = 98;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/tree.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_blue_orb(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 100;
	test[1] = 100;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/blue_orb.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_character(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 127;
	test[1] = 107;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/character_front.xpm",
			&test[0], &test[1]);
	return (img);
}

int	get_position_x(t_vars *vars)
{
	int		c;
	int		l;

	l = 0;
	c = 0;
	while (l < vars->line)
	{
		while (c < vars->col)
		{
			if (vars->map[l][c] == 'P')
			{
				return ((c * 100));
			}
			c++;
		}
		c = 0;
		l++;
	}
	exit_error(ERROR_COMPONENT, vars);
	return (0);
}

int	get_position_y(t_vars *vars)
{
	int		c;
	int		l;

	l = 0;
	c = 0;
	while (l < vars->line)
	{
		while (c < vars->col)
		{
			if (vars->map[l][c] == 'P')
				return ((l * 100));
			c++;
		}
		c = 0;
		l++;
	}
	exit_error(ERROR_COMPONENT, vars);
	return (0);
}
