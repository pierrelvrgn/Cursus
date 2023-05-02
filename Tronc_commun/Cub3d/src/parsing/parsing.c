/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:34:16 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/23 08:13:23 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parsing(t_cub *data, char *file)
{
	ft_check_filename(data, file);
	ft_check_texture(data);
	ft_check_color(data);
	ft_check_map(data);
}
