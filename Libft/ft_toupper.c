/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:42:52 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/04 10:13:31 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int character)
{
	if (character >= 97 && character <= 122)
		character -= 32;
	return (character);
}

/*
#include <ctype.h>

int	main(void)
{
	printf("FT_TOUPPER :\n%d  ||  ", toupper(' '));
	printf("%d\n\n------------------------------------", ft_toupper(' '));
}
*/
