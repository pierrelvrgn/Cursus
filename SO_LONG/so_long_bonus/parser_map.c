/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:25:41 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 13:35:27 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *map)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	return (i);
}

int	count_map(char	*map)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str[i] != '\n')
		i++;
	close(fd);
	free(str);
	return (i);
}

char	**parser_map(char *map, t_vars *vars)
{
	int		fd;
	char	**str;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_file(ERROR_PATH_FILE);
	str = malloc(sizeof(char *) * (count_line(vars->path_map) + 1));
	if (count_line(vars->path_map) <= 0)
		exit_file(ERROR_FILE);
	while (i < count_line(vars->path_map))
	{
		str[i] = get_next_line(fd);
		i++;
	}
	str[i] = 0;
	close(fd);
	return (str);
}

void	exit_error(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	if (count_line(vars->path_map) < 1)
	{
		free(vars->map);
		printf("Error\n%s", str);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (vars->map[i])
		{
			free(vars->map[i]);
			i++;
		}
		printf("Error\n%s", str);
		exit(EXIT_FAILURE);
	}
}

void	exit_file(char *str)
{
	printf("Error\n%s", str);
	exit(EXIT_FAILURE);
}
