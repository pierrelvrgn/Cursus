/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:06:15 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/23 09:24:42 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_control *control, int len)
{
	t_pile	*tmp;
	int		nb;

	nb = 0;
	tmp = control->list_a;
	while (tmp && nb < len)
	{
		if (nb > tmp->pos)
			return (0);
		nb++;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_algo_500(t_control *control)
{
	int	i;
	int	j;
	int	k;
	int	len;

	len = ft_len_pile_a(control);
	j = 0;
	while (!ft_is_sort(control, len))
	{
		i = 0;
		while (i < len)
		{
			k = control->list_a->pos >> j;
			if ((k & 1) == 1)
				ft_rotate_a(control);
			else
				ft_push_b(control);
			i++;
		}
		while (control->list_b)
			ft_push_a(control);
		j++;
	}
}

void	ft_sort_3(t_control *control, int tab[])
{
	if (ft_is_sort(control, ft_len_pile_a(control)))
		exit(EXIT_SUCCESS);
	if (tab[0] == 1 && tab[1] == 2 && tab[2] == 0)
	{
		ft_reverse_rotate_a(control);
	}
	else if (tab[0] == 1 && tab[1] == 0 && tab[2] == 2)
	{
		ft_swap_a(control);
	}
	else if (tab[0] == 0 && tab[1] == 2 && tab[2] == 1)
	{
		ft_swap_a(control);
		ft_rotate_a(control);
	}
	else if (tab[0] == 2 && tab[1] == 0 && tab[2] == 1)
	{
		ft_rotate_a(control);
	}
	else if (tab[0] == 2 && tab[1] == 1 && tab[2] == 0)
	{
		ft_swap_a(control);
		ft_reverse_rotate_a(control);
	}
}
