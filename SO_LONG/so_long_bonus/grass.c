/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grass.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:54:03 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 08:11:53 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_grass(t_vars *vars)
{
	int		i[5];
	void	*img;

	i[0] = 0;
	i[1] = 0;
	i[2] = 100;
	i[3] = 100;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/green.xpm", &i[2], &i[3]);
	while (i[1] < vars->line)
	{
		while (i[0] < (vars->col))
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, img,
				(i[2] * i[0]), (i[2] * i[1]));
			i[0] = i[0] + 1;
		}
		i[0] = 0;
		i[1] = i[1] + 1;
	}
}

void	*get_enemy(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 100;
	test[1] = 100;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/enemy.xpm",
			&test[0], &test[1]);
	return (img);
}

void	print_enemy(t_vars *vars, void *img)
{
	int	i;

	i = 0;
	while (i < vars->initial_enemy)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, img,
			vars->get_enemy[i][0], vars->get_enemy[i][1]);
		i++;
	}
	mlx_destroy_image(vars->mlx, img);
}

void	enemy_attack(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->initial_enemy)
	{
		if (vars->get_enemy[i][0] == vars->x &&
			vars->get_enemy[i][1] == vars->y)
		{
			exit_player(PLAYER_DIE, vars);
		}
		i++;
	}
}

void	exit_player(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	printf("Game Over\n%s", str);
	exit(EXIT_SUCCESS);
}
