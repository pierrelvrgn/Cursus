/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:00:16 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/05 16:56:14 by plavergn         ###   ########.fr       */
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
/*
#include <string.h>

int	main(void)
{
	char	*str;
	char	c;

	c = 'a';
	str = "bien le bonjour abcdef a";
	printf("FT_STRCHR :\n%s  ||  ", strchr(str, c));
	printf("%s\n\n------------------------------------", ft_strchr(str, c));
}
*/
