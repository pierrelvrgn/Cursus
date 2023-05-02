/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 08:48:49 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/04 10:35:01 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "cub3d.h"

char	*get_next_line(int fd);
int		ft_strlennl(char *src, int nb);
char	*ft_strdup(char *source);
char	*ft_strjoin(char *s1, char *s2);
void	new_buffer(char *str);

#endif
