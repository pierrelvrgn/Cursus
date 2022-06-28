/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_for_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:23:47 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/23 09:26:56 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3_for_5(t_control *control, int tab[])
{
	if (tab[0] == 3 && tab[1] == 4 && tab[2] == 2)
	{
		ft_reverse_rotate_a(control);
	}
	else if (tab[0] == 3 && tab[1] == 2 && tab[2] == 4)
	{
		ft_swap_a(control);
	}
	else if (tab[0] == 2 && tab[1] == 4 && tab[2] == 3)
	{
		ft_swap_a(control);
		ft_rotate_a(control);
	}
	else if (tab[0] == 4 && tab[1] == 2 && tab[2] == 3)
	{
		ft_rotate_a(control);
	}
	else if (tab[0] == 4 && tab[1] == 3 && tab[2] == 2)
	{
		ft_swap_a(control);
		ft_reverse_rotate_a(control);
	}
}

static void	ft_push_first(t_control *control, int index)
{
	if (index == 0)
		ft_push_b(control);
	else if (index == 1)
	{
		ft_rotate_a(control);
		ft_push_b(control);
	}
	else if (index == 2)
	{
		ft_rotate_a(control);
		ft_rotate_a(control);
		ft_push_b(control);
	}
	else if (index == 3)
	{
		ft_reverse_rotate_a(control);
		ft_reverse_rotate_a(control);
		ft_push_b(control);
	}
	else if (index == 4)
	{
		ft_reverse_rotate_a(control);
		ft_push_b(control);
	}
}

static void	ft_push_second(t_control *control, int index)
{
	if (index == 0)
		ft_push_b(control);
	else if (index == 1)
	{
		ft_rotate_a(control);
		ft_push_b(control);
	}
	else if (index == 2)
	{
		ft_rotate_a(control);
		ft_rotate_a(control);
		ft_push_b(control);
	}
	else if (index == 3)
	{
		ft_reverse_rotate_a(control);
		ft_push_b(control);
	}
}

static void	ft_push_2(t_control *control)
{
	t_pile	*pile_a;
	int		index;
	int		a;

	a = 0;
	pile_a = control->list_a;
	index = 0;
	while (a < 2)
	{
		while (pile_a && !(pile_a->pos == 0 || pile_a->pos == 1))
		{
			index++;
			pile_a = pile_a->next;
		}
		if (a == 0)
			ft_push_first(control, index);
		else
			ft_push_second(control, index);
		a++;
		pile_a = control->list_a;
		index = 0;
	}
}

void	ft_sort_5(t_control *control)
{
	t_pile	*pile_a;
	int		tab[3];
	int		i;

	if (ft_is_sort(control, ft_len_pile_a(control)))
		exit(EXIT_SUCCESS);
	i = 0;
	pile_a = control->list_a;
	ft_push_2(control);
	pile_a = control->list_a;
	while (pile_a && i < 3)
	{
		tab[i] = pile_a->pos;
		pile_a = pile_a->next;
		i++;
	}
	ft_sort_3_for_5(control, tab);
	ft_push_a(control);
	ft_push_a(control);
	if (!ft_is_sort(control, ft_len_pile_a(control)))
		ft_swap_a(control);
}
