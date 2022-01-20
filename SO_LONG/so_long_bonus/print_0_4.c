/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_0_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:34:19 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 09:33:20 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_0(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/0.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_1(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/1.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_2(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/2.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_3(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/3.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_4(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/4.xpm",
			&test[0], &test[1]);
	return (img);
}
