/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:22:38 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/05 16:37:56 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy( void *destination, const void *source, size_t size )
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			i;

	p = (unsigned char *)destination;
	s = (unsigned char *)source;
	i = 0;
	if (!size)
		return (destination);
	if (!destination & !source)
		return (NULL);
	while (i < size)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
/*
int	main(void)
{
	char	buff1[0xF00];
	char	*src;

	src = "nyancat® inside";
	printf("FT_MEMCPY :\n%s  ||  ", ft_memcpy(buff1, src, sizeof(&src)));
	printf("%s\n\n---------------------------", memcpy(buff1, src, sizeof(&src)));
}
*/
