/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:22:43 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/18 11:07:43 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_hook(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(EXIT_SUCCESS);
}

void	ft_front_hook(t_vars *vars)
{
	vars->y = vars->y - 100;
	vars->i++;
	printf("%s%d\n", vars->str, vars->i);
}

void	ft_back_hook(t_vars *vars)
{
	vars->y = vars->y + 100;
	vars->i++;
	printf("%s%d\n", vars->str, vars->i);
}

void	ft_right_hook(t_vars *vars)
{
	vars->x = vars->x + 100;
	vars->i++;
	printf("%s%d\n", vars->str, vars->i);
}

void	ft_left_hook(t_vars *vars)
{
	vars->x = vars->x - 100;
	vars->i++;
	printf("%s%d\n", vars->str, vars->i);
}
