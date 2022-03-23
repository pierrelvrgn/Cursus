/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:12:11 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/23 09:31:36 by plavergn         ###   ########.fr       */
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
