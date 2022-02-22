/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:47:25 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/10 11:52:35 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff [4096][BUFFER_SIZE + 1];
	char		*dest;
	int			j;
	int			i;

	i = 0;
	j = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest = ft_strdup(buff[fd]);
	while (j > 0 && buff[fd][i] != '\n')
	{
		i = 0;
		while (buff[fd][i] && buff[fd][i] != '\n')
			i++;
		if (buff[fd][i] != '\n')
		{
			j = read(fd, buff[fd], BUFFER_SIZE);
			buff[fd][j] = '\0';
			dest = ft_strjoin(dest, buff[fd]);
		}
	}
	new_buffer(buff[fd]);
	return (dest);
}
