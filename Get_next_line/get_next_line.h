/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 08:48:49 by plavergn          #+#    #+#             */
/*   Updated: 2021/12/13 16:04:39 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlennl(char *src, int nb);
char	*ft_strdup(char *source);
char	*ft_strjoin(char *s1, char *s2);
void	new_buffer(char *str);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
