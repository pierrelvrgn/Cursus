/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:58:37 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/25 09:57:46 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_xpm(t_cub *data, char *textures)
{
	int	i;

	i = 0;
	if (!textures)
		exit(1);
	while (textures[i])
		i++;
	while (textures[i] != '.')
	{
		i--;
		if (i == 0)
			ft_exit(1, "FT_CHECK_TEXTURES_UTILS_XPM", data);
	}
	if (textures[i + 1] && textures[i + 1] && textures[i + 1]
		&& !(textures[i + 1] == 'x' && textures[i + 2]
			== 'p' && textures[i + 3] == 'm'))
		ft_exit(1, "FT_CHECK_TEXTURES_UTILS_XPM", data);
}

void	check_path(t_cub *data, char *text, char *type)
{
	data->map.fd = open(text, O_DIRECTORY);
	if (data->map.fd != -1)
		ft_exit(1, "FT_CHECK_TEXTURES_UTILS_DIRECTORY", data);
	close(data->map.fd);
	data->map.fd = open(text, O_RDONLY);
	if (data->map.fd == -1)
		ft_exit(1, "FT_CHECK_TEXTURES_UTILS_OPEN", data);
	close(data->map.fd);
	if (type[0] == 'N' && type[1] == 'O')
		data->colors.text[NO] = text;
	if (type[0] == 'W' && type[1] == 'E')
		data->colors.text[WE] = text;
	if (type[0] == 'E' && type[1] == 'A')
		data->colors.text[EA] = text;
	if (type[0] == 'S' && type[1] == 'O')
		data->colors.text[SO] = text;
}

void	check_file_path(t_cub *data, char *textures, char *type)
{
	int		i;
	int		x;
	int		index;
	char	*text;

	i = 0;
	index = 0;
	while (textures[i] && textures[i] != '.')
		i++;
	i += 2;
	x = ft_strlen_nl(&textures[i]);
	text = malloc(sizeof(char) * (x + 1));
	if (!text)
		ft_exit(1, "FT_CHECK_TEXTURES_UTILS_MALLOC", data);
	x += i;
	while (i < x)
	{
		text[index] = textures[i];
		index++;
		i++;
	}
	text[index] = '\0';
	check_path(data, text, type);
}
