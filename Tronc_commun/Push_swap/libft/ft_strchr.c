/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:00:16 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/23 09:31:54 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	size_t	i;
	char	*s;

	s = (char *)string;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)searchedChar)
			return (&s[i]);
		i++;
	}
	if (searchedChar == '\0')
		return (&s[i]);
	return (NULL);
}
