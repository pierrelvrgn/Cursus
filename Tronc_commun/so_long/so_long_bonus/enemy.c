/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 07:39:10 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 08:01:13 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_vars *vars)
{
	int	i;

	i = 0;
	get_enemy_number(vars);
	vars->initial_enemy = vars->enemy;
	vars->get_enemy = malloc(sizeof(int *) * vars->enemy);
	while (i < vars->enemy)
	{
		vars->get_enemy[i] = malloc(sizeof(int **) * 2);
		i++;
	}
	get_enemy_position(vars);
}

void	get_enemy_number(t_vars *vars)
{
	int	l;
	int	c;

	c = 0;
	l = 0;
	vars->enemy = 0;
	while (l < vars->line)
	{
		while (c < vars->col)
		{
			if (vars->map[l][c] == 'B')
			{
				vars->enemy++;
			}
			c++;
		}
		c = 0;
		l++;
	}
	if (vars->enemy == 0)
		exit_error(ERROR_COMPONENT, vars);
}

void	get_enemy_position(t_vars *vars)
{
	int		l;
	int		c;
	int		i;

	i = 0;
	l = 0;
	c = 0;
	while (l < vars->line)
	{
		while (c < vars->col)
		{
			if (vars->map[l][c] == 'B')
			{
				vars->get_enemy[i][0] = (c * 100);
				vars->get_enemy[i][1] = (l * 100);
				i++;
			}
			c++;
		}
		c = 0;
		l++;
	}
}
