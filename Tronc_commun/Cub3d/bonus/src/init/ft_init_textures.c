/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures_raycast.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:40:49 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/23 13:11:52 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures(t_cub *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->text[i].img = mlx_xpm_file_to_image(data->mlx.mlx,
				data->colors.text[i], &data->text[i].width,
				&data->text[i].height);
		if (!data->text[i].img)
			ft_exit(3, "An error occured while creating window and/or img",
				data);
		data->text[i].addr = mlx_get_data_addr(data->text[i].img,
				&data->text[i].bpp,
				&data->text[i].line_length, &data->text[i].endian);
		if (!data->text[i].addr)
			ft_exit(4, "An error occured while getting the address", data);
		i++;
	}
}
