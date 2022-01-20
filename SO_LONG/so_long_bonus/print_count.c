/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:30 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 13:02:58 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move_count(t_vars *vars)
{
	print_move(vars, get_move(vars));
	if (vars->count < 10)
	{
		print_1_0_0(vars, get_0(vars));
		print_0_1_0(vars, get_0(vars));
		print_0_0_1(vars, init_count_image(vars, vars->count));
	}
	if (vars->count > 9 && vars->count < 100)
	{
		print_1_0_0(vars, get_0(vars));
		print_0_1_0(vars, init_count_image(vars, (vars->count / 10)));
		print_0_0_1(vars, init_count_image(vars, (vars->count % 10)));
	}
	if (vars->count > 99 && vars->count < 1000)
	{
		print_1_0_0(vars, init_count_image(vars, (vars->count / 100)));
		print_0_1_0(vars, init_count_image(vars, (vars->count / 10 % 10)));
		print_0_0_1(vars, init_count_image(vars, (vars->count % 10)));
	}
	if (vars->count > 999)
	{
		exit_noob(NOOB, vars);
	}
}

void	*get_move(t_vars *vars)
{
	void	*img;
	int		test[2];

	test[0] = 100;
	test[1] = 20;
	img = mlx_xpm_file_to_image(vars->mlx, "assets/move.xpm",
			&test[0], &test[1]);
	return (img);
}

void	*init_count_image(t_vars *vars, int n)
{
	if (n == 0)
		return (get_0(vars));
	if (n == 1)
		return (get_1(vars));
	if (n == 2)
		return (get_2(vars));
	if (n == 3)
		return (get_3(vars));
	if (n == 4)
		return (get_4(vars));
	if (n == 5)
		return (get_5(vars));
	if (n == 6)
		return (get_6(vars));
	if (n == 7)
		return (get_7(vars));
	if (n == 8)
		return (get_8(vars));
	if (n == 9)
		return (get_9(vars));
	return (0);
}

void	exit_noob(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	printf("Game Over\n%s", str);
	exit(EXIT_SUCCESS);
}

void	file_path(char *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	if (str[i] != 'r')
		exit_file(ERROR_PATH_FILE);
	if (str[i - 1] != 'e')
		exit_file(ERROR_PATH_FILE);
	if (str[i - 2] != 'b')
		exit_file(ERROR_PATH_FILE);
	if (str[i - 3] != '.')
		exit_file(ERROR_PATH_FILE);
	return ;
}
