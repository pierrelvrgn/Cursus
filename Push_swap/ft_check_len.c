/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:08:03 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/22 17:21:36 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_len(t_control *control)
{
	t_pile	*pile_a;
	int		len;
	int		tab_3[3];
	int		i;

	i = 0;
	len = ft_len_pile_a(control);
	pile_a = control->list_a;
	if (len == 3)
	{
		while (pile_a)
		{
			tab_3[i] = pile_a->pos;
			pile_a = pile_a->next;
			i++;
		}
		ft_sort_3(control, tab_3);
	}
	else if (len == 5)
		ft_sort_5(control);
	else
		ft_algo_500(control);
}
