/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:41:03 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/05 16:43:58 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)pointer1;
	p2 = (unsigned char *)pointer2;
	while (i < size && p1[i] == p2[i])
		i++;
	if (i < size)
		return (p1[i] - p2[i]);
	else
		return (0);
}
/*
int	main(void)
{
	char	*p1;
	char	*p2;
	size_t	size;

	size = 10;
	p1 = "abcdefghE";
	p2 = "abcdefgh";
	printf("FT_MEMCMP :\n%d  ||  ", ft_memcmp(p1, p2, size));
	printf("%d\n\n------------------------------------", memcmp(p1, p2, size));
}
*/
