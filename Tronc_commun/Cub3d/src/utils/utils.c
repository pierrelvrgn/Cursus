/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:45:17 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/11/22 15:39:57 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_between(int min, int nb, int max)
{
	return (min <= nb && nb <= max);
}

float	ft_fbetween(float min, float nb, float max)
{
	return (min <= nb && nb <= max);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = mlx->addr + (y * mlx->line_len
				+ x * (mlx->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	my_mlx_pixel_get(t_texture *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_length
			+ x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}

void	normalize_angle(float *angle)
{
	if (*angle < 0)
		*angle += TWO_PI;
	if (*angle > TWO_PI)
		*angle -= TWO_PI;
}
