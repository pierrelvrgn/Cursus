/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:37:04 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/17 13:45:05 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *str)
{
	int		i;
	int		size;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
		size++;
	}
	return (size);
}
