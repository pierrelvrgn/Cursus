/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:27:28 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/22 15:41:15 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_down(int key, t_cub *data)
{
	if (key == ESC)
		ft_exit(0, "Window closed", data);
	else if (key == W)
		data->keys.w = 1;
	else if (key == A)
		data->keys.a = 1;
	else if (key == S)
		data->keys.s = 1;
	else if (key == D)
		data->keys.d = 1;
	else if (key == L_ARROW)
		data->keys.l_arrow = 1;
	else if (key == R_ARROW)
		data->keys.r_arrow = 1;
	return (key);
}

int	key_up(int key, t_cub *data)
{
	if (key == ESC)
		ft_exit(0, "Window closed", data);
	else if (key == W)
		data->keys.w = 0;
	else if (key == A)
		data->keys.a = 0;
	else if (key == S)
		data->keys.s = 0;
	else if (key == D)
		data->keys.d = 0;
	else if (key == L_ARROW)
		data->keys.l_arrow = 0;
	else if (key == R_ARROW)
		data->keys.r_arrow = 0;
	return (key);
}
