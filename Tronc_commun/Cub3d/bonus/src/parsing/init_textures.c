/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:52:03 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/23 09:47:39 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_no(t_cub *data, char **textures)
{
	int	i;

	i = 0;
	while (textures[i])
	{
		if (textures[i][0] == 'N' && textures[i][1] == 'O')
			break ;
		i++;
	}
	check_xpm(data, textures[i]);
	check_file_path(data, textures[i], "NO");
}

void	ft_init_we(t_cub *data, char **textures)
{
	int	i;

	i = 0;
	while (textures[i])
	{
		if (textures[i][0] == 'W' && textures[i][1] == 'E')
			break ;
		i++;
	}
	check_xpm(data, textures[i]);
	check_file_path(data, textures[i], "WE");
}

void	ft_init_ea(t_cub *data, char **textures)
{
	int	i;

	i = 0;
	while (textures[i])
	{
		if (textures[i][0] == 'E' && textures[i][1] == 'A')
			break ;
		i++;
	}
	check_xpm(data, textures[i]);
	check_file_path(data, textures[i], "EA");
}

void	ft_init_so(t_cub *data, char **textures)
{
	int	i;

	i = 0;
	while (textures[i])
	{
		if (textures[i][0] == 'S' && textures[i][1] == 'O')
			break ;
		i++;
	}
	check_xpm(data, textures[i]);
	check_file_path(data, textures[i], "SO");
}
