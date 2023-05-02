/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 06:50:12 by plavergn          #+#    #+#             */
/*   Updated: 2022/12/01 14:22:30 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_line(char *read)
{
	int		i;
	int		bool_char;

	i = 0;
	bool_char = 0;
	while (read[i])
	{
		if (read[i] != ' ' && read[i] != '0' && read[i] != '1'
			&& read[i] != '2' && read[i] != 'N' && read[i] != 'S'
			&& read[i] != 'E' && read[i] != 'W' && read[i] != '\n'
			&& read[i] != '\t' && read[i] != '\r')
			return (0);
		else if (read[i] == '0' || read[i] == '1')
			bool_char = 1;
		i++;
	}
	return (bool_char);
}

void	put_map(t_cub *data, char *read)
{
	int		i;
	int		size_line;

	i = 0;
	data->map.length = data->map.sizeline;
	while (read)
	{
		if (check_line(read) == 1)
		{
			size_line = ft_strlen_char(data, read);
			data->map.map[i] = malloc(sizeof(char) * (data->map.sizeline + 1));
			if (!data->map.map[i])
				ft_exit(1, "MALLOC_MAP", data);
			data->map.map[i] = ft_substr(data, data->map.map[i],
					read, size_line);
		}
		else
			ft_exit(1, "MAP", data);
		free(read);
		read = get_next_line(data->map.fd);
		i++;
	}
	data->map.map[i] = NULL;
	free(read);
	close(data->map.fd);
}

void	count_line(t_cub *data, char *read)
{
	int		line;

	line = 0;
	while (read)
	{
		if (check_line(read) == 1)
		{
			if (data->map.sizeline < ft_strlen_char(data, read))
				data->map.sizeline = ft_strlen_char(data, read);
			line++;
		}
		else
			break ;
		free(read);
		read = get_next_line(data->map.fd);
	}
	if (line < 3)
		ft_exit(1, "BAD_MAP", data);
	data->map.map = malloc(sizeof(char *) * (line + 1));
	if (!data->map.map)
		ft_exit(1, "MALLOC_MAP", data);
	data->map.map[line] = NULL;
	data->map.height = line;
	free(read);
	close(data->map.fd);
}

void	init_map_char(t_cub *data)
{
	char	*read;

	read = get_next_line(data->map.fd);
	while (read && check_line(read) == 0)
	{
		free(read);
		read = get_next_line(data->map.fd);
	}
	count_line(data, read);
	data->map.fd = open(data->map.file, O_RDONLY);
	read = get_next_line(data->map.fd);
	while (read && check_line(read) == 0)
	{
		free(read);
		read = get_next_line(data->map.fd);
	}
	put_map(data, read);
}

void	ft_check_map(t_cub *data)
{
	data->map.fd = open(data->map.file, O_RDONLY);
	if (!data->map.fd)
		ft_exit(1, "FT_CHECK_MAP_OPEN", data);
	init_map_char(data);
	close(data->map.fd);
	return ;
}
