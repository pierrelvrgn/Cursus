/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:42:04 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/16 12:33:02 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *source, size_t size)
{
	char	*dest;

	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, source, size);
	dest[size] = 0;
	return (dest);
}

static int	check(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		a;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	result = ft_calloc(check(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		a = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != a)
			result[j++] = ft_strndup(&s[a], (i - a));
	}
	return (result);
}
/*
int	main(void)
{
	char	*s;
	char	c;

	c = ' ';
	s = "  bien  le bom   jce   ";
	printf("%s", *ft_split(s, c));
}
*/
