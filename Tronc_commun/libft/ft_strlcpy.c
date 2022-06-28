/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:55:39 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/12 10:51:22 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*dest;
	char	*src;
	size_t	size;

	dest = malloc(sizeof(char) * 10);
	src = "123ececerbetb";
	size = 0;
	printf("FT_STRLCPY :\n%zu  ||  ", ft_strlcpy(dest, src, size));
	printf("%zu\n\n------------------------------------", strlcpy(dest, src, size));
	free(dest);
	return (0);
}
*/
