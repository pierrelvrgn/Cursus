/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:23:03 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 11:26:14 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_component(t_vars *vars)
{
	int	l;
	int	c;

	l = 0;
	while (l < vars->line)
	{
		c = 0;
		while (c < vars->col)
		{
			if (!(vars->map[l][c] == 'E' || vars->map[l][c] == 'P'
				|| vars->map[l][c] == 'C'
				|| vars->map[l][c] == '1' || vars->map[l][c] == '0'
				|| vars->map[l][c] == 'B'))
				exit_error(ERROR_CHARACTER, vars);
			if (vars->map[l][c] == 'E')
				vars->e++;
			if (vars->map[l][c] == 'P')
				vars->p++;
			c++;
		}
		l++;
	}
	check_rectangular(vars);
	check_component_duplicate(vars);
}

int	ft_select_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		ft_exit_hook(vars);
	if (keycode == KEY_FRONT)
		if (vars->map[(vars->y / 100) - 1][(vars->x / 100)] != '1')
			ft_front_hook(vars);
	if (keycode == KEY_BACK)
		if (vars->map[(vars->y / 100) + 1][(vars->x / 100)] != '1')
			ft_back_hook(vars);
	if (keycode == KEY_LEFT)
		if (vars->map[(vars->y / 100)][(vars->x / 100) - 1] != '1')
			ft_left_hook(vars);
	if (keycode == KEY_RIGHT)
		if (vars->map[(vars->y / 100)][(vars->x / 100) + 1] != '1')
			ft_right_hook(vars);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	enemy_attack(vars);
	collect_collectible(vars);
	ft_put_grass(vars);
	print_blue_orb(vars, get_blue_orb(vars));
	print_chest(vars, get_chest(vars));
	print_enemy(vars, get_enemy(vars));
	print_character(vars, get_character(vars));
	print_tree(vars, get_tree(vars));
	chest_exit(vars);
	print_move_count(vars);
	return (0);
}

void	check_component_duplicate(t_vars *vars)
{
	if (vars->p > 1)
		exit_error(ERROR_DUPLICATE, vars);
	if (vars->e == 0)
		exit_error(ERROR_COMPONENT, vars);
	if (vars->e > 1)
		exit_error(ERROR_DUPLICATE, vars);
}

void	check_rectangular(t_vars *vars)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	if (vars->col == vars->line)
		exit_error(ERROR_MAP, vars);
	while (l < vars->line)
	{
		while (vars->map[l][c] != 0)
		{
			if (c > vars->col || l > vars->line)
				exit_error(ERROR_MAP, vars);
			c++;
		}
		l++;
	}
}
