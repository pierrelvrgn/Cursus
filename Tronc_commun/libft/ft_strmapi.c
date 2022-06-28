/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:19:37 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/11 10:29:40 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*source;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	source = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!source)
		return (NULL);
	while (s[i])
	{
		source[i] = f(i, s[i]);
		i++;
	}
	source[i] = '\0';
	return (source);
}
