/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:43:33 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/18 18:58:25 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_vars *vars)
{
	(void)vars;
	exit(EXIT_SUCCESS);
}

void	check_map(t_vars *vars)
{
	int	c;
	int	l;

	l = 0;
	c = 0;
	while (c < vars->col)
	{
		if (vars->map[0][c] != '1')
			exit_error(ERROR_WALL, vars);
		if (vars->map[vars->line - 1][c] != '1')
			exit_error(ERROR_WALL, vars);
		c++;
	}
	while (l < vars->line)
	{
		if (vars->map[l][0] != '1')
			exit_error(ERROR_WALL, vars);
		if (vars->map[l][vars->col - 1] != '1')
			exit_error(ERROR_WALL, vars);
		l++;
	}
	vars->e = 0;
	vars->p = 0;
	check_component(vars);
}

void	collect_collectible(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->initial_collectible)
	{
		if (vars->get_collectible[i][0] == vars->x &&
			vars->get_collectible[i][1] == vars->y)
		{
			vars->get_collectible[i][0] = 0;
			vars->get_collectible[i][1] = 0;
			vars->collectible--;
		}
		i++;
	}
}

void	vars_init(t_vars *vars)
{
	int	i;

	i = -1;
	vars->str = "Nombre de coups : ";
	vars->map = parser_map(vars->path_map, vars);
	vars->col = count_map(vars->path_map);
	vars->line = count_line(vars->path_map);
	check_map(vars);
	vars->i = 0;
	vars->x = get_position_x(vars);
	vars->y = get_position_y(vars);
	get_collectible_number(vars);
	vars->initial_collectible = vars->collectible;
	vars->get_collectible = malloc(sizeof(int *) * vars->collectible);
	while (++i < vars->collectible)
		vars->get_collectible[i] = malloc(sizeof(int **) * 2);
	get_collectible_position(vars);
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, ((vars->col) * 100),
			(vars->line * 100), "SO_LONG");
	mlx_key_hook(vars->mlx_win, ft_select_hook, vars);
	mlx_hook(vars->mlx_win, 17, 0, ft_exit, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	vars.path_map = argv[1];
	vars_init(&vars);
	free(vars.map);
	return (0);
}
