/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:13:11 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/04 10:34:25 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	if (i < size)
	{
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}
/*
#include <string.h>

int	main(void)
{
	char	*dst;
	char	*src;
	size_t	size;

	dst = "bonjour";
	src = "bienle";
	size = 7;
	printf("FT_STRLCAT :\n%zu  ||  ",
		ft_strlcat(dst, src, size));
	printf("%zu\n\n------------------------------------",
		strlcat(dst, src, size));
}
*/
