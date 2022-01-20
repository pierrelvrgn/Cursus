/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:46:02 by plavergn          #+#    #+#             */
/*   Updated: 2022/01/19 16:53:42 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_pile_a(int argc, char **argv, t_struct *sort)
{
	int i;

	i = 1;
	sort->pile_a = malloc(sizeof(int *) * (argc - 1));
	while (i < argc)
	{
		sort->pile_a = (int)argv[i];
		i++;
	}
	return ;
}

