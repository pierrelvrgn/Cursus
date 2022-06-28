/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:47:15 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/23 09:31:49 by plavergn         ###   ########.fr       */
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
