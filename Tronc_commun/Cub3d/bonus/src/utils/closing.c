/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:10:07 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/01 14:18:58 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_colors_and_map(t_cub *data)
{
	if (data->colors.text[NO])
		free(data->colors.text[NO]);
	if (data->colors.text[SO])
		free(data->colors.text[SO]);
	if (data->colors.text[EA])
		free(data->colors.text[EA]);
	if (data->colors.text[WE])
		free(data->colors.text[WE]);
	free_map_struct(data);
}

void	destroy_img(t_cub *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->text[i].img)
			mlx_destroy_image(data->mlx.mlx, data->text[i].img);
		i++;
	}
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
}

void	ft_exit(int status, char *msg, t_cub *data)
{
	if (status != 0)
		printf("Error\n");
	printf("%s\n", msg);
	exit (status);
	if (data)
	{
		free_colors_and_map(data);
		destroy_img(data);
		if (data->mlx.mlx_win)
			mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
		if (data->mlx.mlx)
			free(data->mlx.mlx);
		free(data);
	}
}

int	close_win(t_cub *data)
{
	ft_exit(0, "Window closed", data);
	return (0);
}
