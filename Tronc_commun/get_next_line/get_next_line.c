/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 08:48:41 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/31 10:30:23 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE +1];
	char		*dest;
	int			j;
	int			i;

	i = 0;
	j = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest = ft_strdup(buff);
	while (j > 0 && buff[i] != '\n')
	{
		i = 0;
		while (buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] != '\n')
		{
			j = read(fd, buff, BUFFER_SIZE);
			buff[j] = '\0';
			dest = ft_strjoin(dest, buff);
		}
	}
	new_buffer(buff);
	return (dest);
}
