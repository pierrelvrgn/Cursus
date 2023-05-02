/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:34:18 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/24 15:02:25 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FUNCTIONS_H
# define CUB3D_FUNCTIONS_H

# include "cub3d.h"

/********************************************/
/*					init					*/
/********************************************/

/*			init_struct.c					*/

void		init_params(t_cub *data);
void		init_player(t_cub *data);
void		init_controls(t_cub *data);

/*			ft_init_textures.c				*/

void		init_textures(t_cub *data);

/*			ft_init_map.c					*/

void		ft_init_map(t_cub *cub);

/********************************************/
/*					movement				*/
/********************************************/

/*			movement.c 						*/

void		move_forward(t_cub *data);
void		move_backward(t_cub *data);
void		left_move(t_cub *data);
void		right_move(t_cub *data);
void		check_moves(t_cub *data);

/*			movement_utils.c 				*/

int			map_has_wall_at(t_cub *data, float x, float y);
void		use_mouse(t_cub *data);

/*			ft_select_hook.c 				*/

int			key_down(int key, t_cub *data);
int			key_up(int key, t_cub *data);

/********************************************/
/*					parsing		 			*/
/********************************************/

/*			parsing_map.c					*/

void		check_map_wall(t_cub *data);
void		check_player(t_cub *data);

/*			ft_init_textures.c				*/

void		ft_init_no(t_cub *data, char **textures);
void		ft_init_we(t_cub *data, char **textures);
void		ft_init_ea(t_cub *data, char **textures);
void		ft_init_so(t_cub *data, char **textures);

/*			ft_check_filename.c 			*/

void		ft_check_filename(t_cub *data, char *file);

/*			pasring/parsing.c				*/

void		parsing(t_cub *data, char *file);

/*			ft_check_color.c 				*/

void		ft_check_color(t_cub *data);

/*			ft_check_map.c 					*/

void		ft_check_map(t_cub *data);

/*			ft_check_texture.c 				*/

void		ft_check_texture(t_cub *data);

/*			ft_check_textures_utils.c		*/

void		check_xpm(t_cub *data, char *textures);
void		check_file_path(t_cub *data, char *textures, char *type);

/*			check_space.c					*/

void		check_line_before(t_cub *data, char **map, int line, int column);
void		check_column_before(t_cub *data, char **map, int line, int column);
void		check_next_line(t_cub *data, char **map, int line, int column);
void		check_next_column(t_cub *data, char **map, int line, int column);

/********************************************/
/*					utils					*/
/********************************************/

/*			string_utils.c					*/

int			ft_strlen(char *str);
int			ft_strlen_nl(char *str);
char		*ft_substr(t_cub *data, char *str, char *read, int size);
int			ft_strlen_char(t_cub *data, char *str);

/*			random_utils.c					*/

void		create_color(t_cub *data, char color_type, int color_rgb[3]);
void		free_map_struct(t_cub *data);
int			ft_atoi_color(char *nb, int index_max);

/*			closing.c						*/

void		free_colors_and_map(t_cub *data);
void		destroy_img(t_cub *data);
void		ft_exit(int status, char *msg, t_cub *data);
int			close_win(t_cub *data);

/*			utils.c						*/

int			my_mlx_pixel_get(t_texture *texture, int x, int y);
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int			ft_between(int min, int nb, int max);
float		ft_fbetween(float min, float nb, float max);
void		normalize_angle(float *angle);

/********************************************/
/*					raycasting				*/
/********************************************/

/*			textures.c 						*/

void		render_colors(t_cub *data);
void		render_textures(t_cub *data);
void		render_strip_texture(t_cub *data, int x, int y, int height);
float		get_strip_texture(t_cub *data, int x);

/*			raycasting.c 						*/

void		cast_all_rays(t_cub *data);
void		cast_ray(t_cub *data, t_ray *ray, int strip_id);
void		vert_intersection(t_cub *data, t_ray *ray);
void		horz_intersection(t_cub *data, t_ray *ray);
float		distance_between_points(float x1, float y1, float x2, float y2);

#endif
