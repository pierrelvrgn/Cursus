/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:42:01 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/05 11:29:37 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*call;

	call = malloc(elementCount * elementSize);
	if (!call)
		return (0);
	ft_bzero(call, elementSize * elementCount);
	return (call);
}
/*
int	main(void)
{
	int	count;
	int	size;
	int	*test;

	count = 3000;
	size = 10000;
	test = calloc(count, size);
	printf("%d", *test);
	free (test);
}
*/
