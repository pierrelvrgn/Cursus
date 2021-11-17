/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:47:15 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/05 16:41:32 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove( void *destination, const void *source, size_t size )
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	i = 0;
	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!destination && !source)
		return (NULL);
	if (dst >= src)
	{
		while (size-- > 0)
			dst[size] = src[size];
	}
	else
	{
		i -= 1;
		while (++i, size--)
			dst[i] = src[i];
	}
	return (dst);
}
/*
int	main(int argc, char **argv)
{
	char	*dest;
	char	*test;
	char	*dst;

	test = "ceci est un test";
	dest = ft_strdup(argv[1]);
	//dst = malloc(sizeof(char) * 1);
	test = ft_strdup(argv[2]);
	printf("\n%s\n", ft_memmove(dest, test, ft_strlen(test)));
	printf("%s",
		memmove(dest, test, ft_strlen(test)));
	free (dest);
	free (dst);
	return (0);
}
*/
