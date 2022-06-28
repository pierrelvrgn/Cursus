/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:15:01 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/12 09:11:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	int		a;
	int		b;
	char	*s2;

	a = ft_strlen(s1);
	b = 0;
	s2 = malloc(sizeof(char) * (a + 1));
	if (!s2)
		return (NULL);
	while (b < a)
	{
		s2[b] = s1[b];
		b++;
	}
	s2[b] = '\0';
	return (s2);
}
