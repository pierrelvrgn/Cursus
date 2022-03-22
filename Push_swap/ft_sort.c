/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:06:15 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/22 18:49:15 by plavergn         ###   ########.fr       */
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
//		print_list(control);
		ft_reverse_rotate_a(control);
//		print_list(control);
	}
//	print_list(control);
}

void	ft_sort_3_for_5(t_control *control, int tab[])
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

void	ft_push_first(t_control *control, int index)
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

void	ft_push_second(t_control *control, int index)
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

void	ft_push_2(t_control *control)
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
//	print_list(control);
	ft_push_a(control);
	ft_push_a(control);
//	print_list(control);
	if (!ft_is_sort(control, ft_len_pile_a(control)))
		ft_swap_a(control);
}
