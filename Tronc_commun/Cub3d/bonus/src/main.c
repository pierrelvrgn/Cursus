/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:35:55 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/04 10:35:55 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	display(t_cub *data)
{
	check_moves(data);
	render_colors(data);
	cast_all_rays(data);
	render_textures(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->mlx.img, 0, 0);
	mlx_do_sync(data->mlx.mlx);
	return (0);
}

void	init_data(char *filename, t_cub *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		ft_exit(2, "An error occured while using mlx", data);
	init_params(data);
	parsing(data, filename);
	check_player(data);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D_bonus");
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->mlx.mlx_win || !data->mlx.img)
		ft_exit(2, "An error occured while using mlx", data);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.line_len, &data->mlx.endian);
	if (!data->mlx.addr)
		ft_exit(2, "An error occured while using mlx", data);
	init_controls(data);
	init_player(data);
	init_textures(data);
}

int	main(int argc, char **argv)
{
	t_cub	*data;

	if (argc != 2)
		ft_exit(-1, "Wrong number of arguments", 0);
	data = (t_cub *)malloc(sizeof(t_cub));
	if (!data)
		ft_exit(1, "Malloc error", data);
	init_data(argv[1], data);
	check_map_wall(data);
	mlx_mouse_hide();
	mlx_hook(data->mlx.mlx_win, 2, 1L << 0, key_down, data);
	mlx_hook(data->mlx.mlx_win, 3, 1L << 1, key_up, data);
	mlx_hook(data->mlx.mlx_win, 17, (1L << 17), close_win, data);
	mlx_loop_hook(data->mlx.mlx, display, data);
	mlx_loop(data->mlx.mlx);
	exit(0);
}
