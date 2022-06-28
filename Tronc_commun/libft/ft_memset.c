/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:25:39 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/03 11:26:11 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)pointer;
	while (i != count)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
