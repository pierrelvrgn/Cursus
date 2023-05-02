/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:59:23 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/25 10:16:57 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_textures(t_cub *data, char **textures)
{
	int	i;

	i = 0;
	while (textures[i])
		i++;
	if (i != 4)
		ft_exit(1, "FT_CHECK_TEXTURES_TEXTURES_NEED", data);
	ft_init_no(data, textures);
	ft_init_we(data, textures);
	ft_init_ea(data, textures);
	ft_init_so(data, textures);
}

static int	pars_textures(char *read)
{
	if ((read[0] == 'N' && read[1] == 'O' && (read[2] == ' '
				|| read[2] == '\t')) || (read[0] == 'W'
			&& read[1] == 'E' && (read[2] == ' '
				|| read[2] == '\t')) || (read[0] == 'E' && read[1]
			== 'A' && (read[2] == ' ' || read[2] == '\t')) || (read[0]
			== 'S' && read[1] == 'O' && (read[2] == ' '
				|| read[2] == '\t')))
		return (1);
	else
		return (0);
}

char	**ft_check_read(t_cub *data, char *read, char **textures)
{
	if (read[0] && read[1] && read[2])
	{
		if (pars_textures(read) == 1)
		{
			textures[data->map.index] = read;
			data->map.index++;
		}
		else
			free(read);
	}
	else
		free(read);
	return (textures);
}

static void	init_textures_str(t_cub *data)
{
	char	*read;
	char	**textures;
	int		i;

	textures = malloc(sizeof(char *) * 5);
	if (!textures)
		ft_exit(1, "FT_CHECK_TEXTURES_MALLOC_TEXTURES", data);
	textures[4] = NULL;
	data->map.index = 0;
	read = get_next_line(data->map.fd);
	while (read)
	{
		textures = ft_check_read(data, read, textures);
		read = get_next_line(data->map.fd);
	}
	free(read);
	if (data->map.index != 4)
		ft_exit(1, "TEXTURES", data);
	check_textures(data, textures);
	i = 0;
	while (i < 4)
		free(textures[i++]);
	free(textures);
}

void	ft_check_texture(t_cub *data)
{
	data->map.fd = open(data->map.file, O_RDONLY);
	if (!data->map.fd)
		ft_exit(1, "FT_CHECK_TEXTURES_OPEN", data);
	init_textures_str(data);
	close(data->map.fd);
	return ;
}
