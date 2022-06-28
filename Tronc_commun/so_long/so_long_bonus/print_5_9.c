/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_5_9.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:34:19 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 09:12:17 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_5(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/5.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_6(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/6.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_7(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/7.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_8(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/8.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*get_9(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 20;
	test[1] = 15;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/9.xpm",
			&test[0], &test[1]);
	return (img);
}
