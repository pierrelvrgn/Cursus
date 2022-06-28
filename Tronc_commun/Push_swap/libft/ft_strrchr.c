/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:40:58 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/23 09:32:14 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		j;
	char	*str;

	i = 0;
	j = -1;
	str = (char *)s;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			j = i;
		i ++;
	}
	if (c == '\0')
		return (&str[i]);
	if (j == -1)
		return (NULL);
	return (&str[j]);
}
