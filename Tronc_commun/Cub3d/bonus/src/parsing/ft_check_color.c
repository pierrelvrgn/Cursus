/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:59:31 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/23 13:10:59 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	hex_convertor(t_cub *data, char *nb, int index_max, char color_type)
{
	int	i;
	int	index;
	int	tmp;
	int	color_rgb[3];

	i = 0;
	index = 0;
	while (i < index_max)
	{
		if (nb[i] >= '0' && nb[i] <= '9')
		{
			tmp = i;
			while (nb[i] && nb[i] >= '0' && nb[i] <= '9')
				i++;
			color_rgb[index] = ft_atoi_color(&nb[tmp], i - tmp);
			if (color_rgb[index] < 0 || color_rgb[index] > 255)
				ft_exit(1, "BAD_COLOR", data);
			index++;
		}
		i++;
	}
	create_color(data, color_type, color_rgb);
}

void	check_end_of_line(t_cub *data, int i, char *read)
{
	while (read[i])
	{
		if (!(read[i] == '\n' || read[i] == ' '
				|| read[i] == '\t' || read[i] == '\r'))
			ft_exit(1, "INVALID_COLOR", data);
		i++;
	}
}

void	add_color(t_cub *data, char *read)
{
	int		i;
	int		tmp;
	int		comma;

	i = 1;
	comma = 0;
	while (read[i] && (read[i] == ' ' || read[i] == '\t'))
		i++;
	if (!(read[i] >= '0' && read[i] <= '9'))
		ft_exit(1, "INVALID_COLOR", data);
	tmp = i;
	while (read[i] && comma < 3 && (read[i] == ','
			|| (read[i] >= '0' && read[i] <= '9')))
	{
		if (read[i] == ',')
			comma++;
		i++;
	}
	if (comma == 2 && read[i])
		hex_convertor(data, &read[tmp], i - tmp, read[0]);
	check_end_of_line(data, i, read);
}

void	check_color_value(t_cub *data)
{
	char	*read;

	read = get_next_line(data->map.fd);
	while (read)
	{
		if (read && read[0])
			if (read[0] == 'F' || read[0] == 'C')
				add_color(data, read);
		free(read);
		read = get_next_line(data->map.fd);
	}
	free(read);
	if (data->colors.ceiling == -1 || data->colors.floor == -1)
		ft_exit(1, "COLOR", data);
}

void	ft_check_color(t_cub *data)
{
	data->map.fd = open(data->map.file, O_RDONLY);
	if (!data->map.fd)
		ft_exit(1, "FT_CHECK_TEXTURES_OPEN", data);
	check_color_value(data);
	close(data->map.fd);
	return ;
}
