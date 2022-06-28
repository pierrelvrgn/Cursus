/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:48:06 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/05 17:06:48 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		if ((unsigned char)first[i] != (unsigned char)second[i])
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		else if (first[i] == '\0' || second[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
#include <string.h>

int	main(void)
{
	char	*f;
	char	*s;
	size_t	l;

	l = 8;
	f = "abcdefgh";
	s = "abcdefg";
	printf("FT_STRNCMP :\n%d  ||  ", strncmp(f, s, l));
	printf("%d\n\n------------------------------------", ft_strncmp(f, s, l));
}
*/
