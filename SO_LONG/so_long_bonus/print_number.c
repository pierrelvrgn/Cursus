/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:46:43 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 09:51:15 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_0_0_1(t_vars *vars, void *img)
{
	int	i;
	int	a;

	i = 125;
	a = 10;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, i, a);
	mlx_destroy_image(vars->mlx, img);
}

void	print_0_1_0(t_vars *vars, void *img)
{
	int	i;
	int	a;

	i = 110;
	a = 10;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, i, a);
	mlx_destroy_image(vars->mlx, img);
}

void	print_1_0_0(t_vars *vars, void *img)
{
	int	i;
	int	a;

	i = 95;
	a = 10;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, i, a);
	mlx_destroy_image(vars->mlx, img);
}

void	print_move(t_vars *vars, void *img)
{
	int	i;
	int	a;

	i = 10;
	a = 10;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, i, a);
	mlx_destroy_image(vars->mlx, img);
}
