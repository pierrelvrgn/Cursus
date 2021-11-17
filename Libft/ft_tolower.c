/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:51:00 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/04 10:13:35 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int character)
{
	if (character >= 65 && character <= 90)
		character += 32;
	return (character);
}

/*
#include <ctype.h>

int	main(void)
{
	printf("FT_TOLOWER :\n%d  ||  ", tolower('C'));
	printf("%d\n\n------------------------------------", ft_tolower('C'));
}
*/
