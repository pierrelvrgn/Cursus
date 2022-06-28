/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:22:43 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 10:06:14 by plavergn         ###   ########.fr       */
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
	vars->count++;
}

void	ft_back_hook(t_vars *vars)
{
	vars->y = vars->y + 100;
	vars->count++;
}

void	ft_right_hook(t_vars *vars)
{
	vars->x = vars->x + 100;
	vars->count++;
}

void	ft_left_hook(t_vars *vars)
{
	vars->x = vars->x - 100;
	vars->count++;
}
