/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:48:28 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/07 10:04:42 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlennl(char *src, int nb)
{
	if (nb == 0)
	{
		while (src[nb])
			nb++;
		return (nb);
	}
	else
	{
		nb = 0;
		while (src[nb] && src[nb] != '\n')
			nb++;
		return (nb);
	}
	return (0);
}

char	*ft_strdup(char *source)
{
	char	*dest;
	int		i;

	i = ft_strlennl(source, 0);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (source[i] && source[i - 1] != '\n')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	if (dest[0] == 0)
	{
		free(dest);
		dest = NULL;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		a;

	i = -1;
	a = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	dest = malloc(sizeof(char) * (ft_strlennl(s1, 0) + ft_strlennl(s2, 1) + 1));
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[a] && s2[a - 1] != '\n')
		dest[i++] = s2[a++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

void	new_buffer(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlennl(str, 1);
	if (str[0] == 0)
	{
		str = NULL;
		return ;
	}
	if (str[j] == '\n')
	{
		j++;
		while (str[j])
		{
			str[i] = str[j];
			i++;
			j++;
		}
	}
	while (i < j)
	{
		str[i] = 0;
		i++;
	}
}
