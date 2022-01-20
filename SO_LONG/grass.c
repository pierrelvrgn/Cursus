/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grass.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:54:03 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/18 13:17:33 by plavergn         ###   ########.fr       */
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
