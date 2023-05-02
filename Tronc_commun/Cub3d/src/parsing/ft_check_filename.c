/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:55:11 by plavergn          #+#    #+#             */
/*   Updated: 2022/12/02 09:49:48 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_filename(t_cub *data, char *file)
{
	int	i;

	i = 0;
	data->map.file = malloc(sizeof(char) * (ft_strlen(file) + 1));
	if (!data->map.file)
		ft_exit(1, "FT_CHECK_FILENAME_MALLOC", data);
	while (file[i])
	{
		data->map.file[i] = file[i];
		i++;
	}
	data->map.file[i] = '\0';
	return ;
}

void	ft_check_filename(t_cub *data, char *file)
{
	int	i;

	i = 0;
	if (!file)
		ft_exit(1, "FT_CHECK_FILENAME_PATH", data);
	while (file[i])
		i++;
	while (file[i] != '.' && i != 0)
		i--;
	if (i == 0)
		ft_exit(1, "FT_CHECK_FILENAME_NAME", data);
	if (!(file[i + 1] == 'c' && file[i + 2] == 'u'
			&& file[i + 3] == 'b' && file[i + 4] == '\0'))
		ft_exit(1, "FT_CHECK_FILENAME_NAME", data);
	data->map.fd = open(file, O_DIRECTORY);
	if (data->map.fd != -1)
		ft_exit(1, "FT_CHECK_FILENAME_DIRECTORY", data);
	close(data->map.fd);
	data->map.fd = open(file, O_RDONLY);
	if (data->map.fd == -1)
		ft_exit(1, "FT_CHECK_FILENAME_OPEN", data);
	close(data->map.fd);
	init_filename(data, file);
	return ;
}
