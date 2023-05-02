/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:34:18 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/24 15:02:44 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTURES_H
# define CUB3D_STRUCTURES_H

typedef struct s_points
{
	float		x;
	float		y;
}				t_points;

typedef struct s_colors
{
	char		*text[4];
	int			ceiling;
	int			floor;
}				t_colors;

typedef struct s_player
{
	t_points	pos;
	t_points	step;
	float		rot_angle;
	int			walk_direction;
}				t_player;

typedef struct s_map
{
	char			p_facing;
	unsigned short	height;
	unsigned short	length;
	char			**map;
	char			*file;
	int				index;
	int				f;
	int				c;
	int				nblines;
	int				sizeline;
	int				fd;
}					t_map;

typedef struct s_ray
{
	float		ray_angle;
	t_points	pos;
	float		a_tan;
	t_points	step;
	float		distance;
	int			wall_text;
	int			wall_height;
	int			strip_id;
}				t_ray;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			screen_center;
}				t_mlx;

typedef struct s_controls
{
	int			w;
	int			a;
	int			d;
	int			s;
	int			l_arrow;
	int			r_arrow;
	int			esc;
}				t_controls;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_texture;

typedef struct s_cub
{
	t_colors	colors;
	t_map		map;
	t_mlx		mlx;
	t_player	player;
	t_controls	keys;
	t_ray		rays[NUM_RAYS];
	t_texture	text[4];
}				t_cub;

#endif
