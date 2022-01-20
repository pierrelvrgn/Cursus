/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:12:11 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/05 16:42:51 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned char	*memblock;
	size_t			i;

	i = 0;
	memblock = (unsigned char *)memoryBlock;
	while (i < size)
	{
		if (memblock[i] == (unsigned char)searchedChar)
			return (&memblock[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*mb;
	char	sc;
	size_t	size;

	mb = "Bonjour je test 123 abcdef";
	sc = '1';
	size = 40;
	printf("FT_MEMCHR :\n%s  ||  ", ft_memchr(mb, sc, size));
	printf("%s\n\n------------------------------------", memchr(mb, sc, size));
}
*/
