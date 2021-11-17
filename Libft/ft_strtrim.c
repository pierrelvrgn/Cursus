/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:38:12 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/12 11:40:58 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	searched_str(char s, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		a;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	a = ft_strlen(s1);
	while (s1[i] && searched_str(s1[i], set))
		i++;
	a--;
	while (a > i && searched_str(s1[a], set))
		a--;
	result = malloc(sizeof(char) * (a - i + 2));
	if (!result)
		return (NULL);
	while (i <= a)
		result[j++] = s1[i++];
	result[j] = '\0';
	return (result);
}
/*
int	main(int argc, char **argv)
{
	printf("%s", ft_strtrim(argv[1], argv[2]));
}

*/
