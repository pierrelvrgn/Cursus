/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:38:43 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/25 17:21:36 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line.h"
# include <stdio.h>

# define KEY_ESC 53
# define KEY_FRONT 13
# define KEY_BACK 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_CLOSE 17
# define COLOR 0x000000
# define ERROR_COMPONENT "Component are missing on the map...\n"
# define ERROR_WALL "Walls are missing on the map...\n"
# define ERROR_MAP "The map is not rectangular...\n"
# define ERROR_FILE "The file is empty...\n"
# define ERROR_CHARACTER "Bad character on the file...\n"
# define ERROR_DUPLICATE "Component are duplicate...\n"
# define ERROR_PATH_FILE "The path of the file is incorrect...\n"

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	char	*path_map;
	int		i;
	char	*str;
	int		x_chest;
	int		y_chest;
	int		col;
	int		line;
	int		collectible;
	int		**get_collectible;
	char	**map;
	int		initial_collectible;
	int		e;
	int		p;
}				t_vars;

void	exit_file(char *str);
void	check_rectangular(t_vars *vars);
void	check_component_duplicate(t_vars *vars);
void	exit_error(char *str, t_vars *vars);
void	check_component(t_vars *vars);
void	check_map(t_vars *vars);
void	ft_put_grass(t_vars *vars);
int		ft_strlen(char	*src);
int		count_map(char	*map);
int		count_line(char *map);
char	**parser_map(char *map, t_vars *vars);
void	*get_tree( t_vars *vars);
void	print_tree(t_vars *vars, void *img);
void	*get_blue_orb(t_vars *vars);
void	*get_character(t_vars *vars);
void	print_blue_orb(t_vars *vars, void *img);
void	print_character(t_vars *vars, void *img);
void	ft_exit_hook(t_vars *vars);
int		get_position_x(t_vars *vars);
int		get_position_y(t_vars *vars);
void	ft_front_hook(t_vars *vars);
void	ft_back_hook(t_vars *vars);
void	ft_right_hook(t_vars *vars);
void	ft_left_hook(t_vars *vars);
int		ft_select_hook(int keycode, t_vars *vars);
int		render_next_frame(t_vars *vars);
void	string_put(t_vars *vars);
char	*strjoin(char *s1, char *s2);
void	*get_chest(t_vars *vars);
void	print_chest(t_vars *vars, void *img);
void	chest_exit(t_vars *vars);
void	get_collectible_position(t_vars *vars);
void	vars_init(t_vars *vars);
void	get_collectible_number(t_vars *vars);
void	collect_collectible(t_vars *vars);

#endif
