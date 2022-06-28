/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:19:20 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/18 18:55:38 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char	*src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	*get_chest(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 100;
	test[1] = 100;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/chest.xpm",
			&test[0], &test[1]);
	return (img);
}

void	chest_exit(t_vars *vars)
{
	if (vars->collectible <= 0)
	{
		if (vars->x == vars->x_chest && vars->y == vars->y_chest)
			ft_exit_hook(vars);
	}
	else
		return ;
}

void	get_collectible_number(t_vars *vars)
{
	int	l;
	int	c;

	c = 0;
	l = 0;
	vars->collectible = 0;
	while (l < vars->line)
	{
		while (c < vars->col)
		{
			if (vars->map[l][c] == 'C')
			{
				vars->collectible++;
			}
			c++;
		}
		c = 0;
		l++;
	}
	if (vars->collectible == 0)
		exit_error(ERROR_COMPONENT, vars);
}

void	get_collectible_position(t_vars *vars)
{
	int		l;
	int		c;
	int		i;

	i = 0;
	c = 0;
	l = 0;
	while (l < vars->line)
	{
		while (c < vars->col)
		{
			if (vars->map[l][c] == 'C')
			{
				vars->get_collectible[i][0] = (c * 100);
				vars->get_collectible[i][1] = (l * 100);
				i++;
			}
			c++;
		}
		c = 0;
		l++;
	}
}
