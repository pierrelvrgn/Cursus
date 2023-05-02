/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:19:53 by plavergn          #+#    #+#             */
/*   Updated: 2022/12/01 14:07:08 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_atoi_color(char *nb, int index_max)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nb[i] && i < index_max)
	{
		result = result * 10 + (nb[i] - 48);
		i++;
	}
	return (result);
}

void	create_color(t_cub *data, char color_type, int color_rgb[3])
{
	if (color_type == 'F')
		data->colors.floor = ((0 << 24 | color_rgb[0] << 16
					| color_rgb[1] << 8 | color_rgb[2]));
	else if (color_type == 'C')
		data->colors.ceiling = ((0 << 24 | color_rgb[0] << 16
					| color_rgb[1] << 8 | color_rgb[2]));
}

void	free_map_struct(t_cub *data)
{
	int	i;

	i = 0;
	if (data->map.map != NULL)
	{
		while (i < data->map.height)
		{
			if (data->map.map[i] == NULL)
				break ;
			free(data->map.map[i]);
			i++;
		}
		free(data->map.map);
	}
	if (data->map.file != NULL)
		free(data->map.file);
	if (data->map.fd != -1)
		close(data->map.fd);
}
