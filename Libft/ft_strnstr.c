/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:57:37 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/05 17:11:31 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	l = (char *)little;
	b = (char *)big;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (b[i] && i < len)
	{
		if (b[i] == l[0])
		{
			j = 0;
			while (b[i + j] == l[j] && i + j < len)
			{
				j++;
				if (l[j] == '\0')
					return (&b[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*big;
	char	*little;
	size_t	len;

	len = 10;
	big = "abcfgdefghi";
	little = "fgh";
	printf("FT_STRNSTR :\n%s  ||  ", strnstr(big, little, len));
	printf("%s\n\n------------------------------------",
		ft_strnstr(big, little, len));
}
*/
