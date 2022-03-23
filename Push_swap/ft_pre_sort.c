/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:06:15 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/23 09:29:31 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort(t_control *control, int place, int index)
{
	int		max;
	t_pile	*actuel;
	int		pos;

	max = 2147483647;
	actuel = control->list_a;
	while (actuel)
	{
		if (actuel->nb <= max && actuel->pos == -1)
		{
			max = actuel->nb;
			pos = index;
		}
		actuel = actuel->next;
		index++;
	}
	index = 0;
	actuel = control->list_a;
	while (index < pos && actuel->next)
	{
		actuel = actuel->next;
		index++;
	}
	actuel->pos = place;
}

static void	sort_pile(t_control *control)
{
	t_pile	*actuel;

	if (control == NULL)
	{
		exit(EXIT_FAILURE);
	}
	actuel = control->list_a;
	while (actuel)
	{
		actuel->pos = -1;
		actuel = actuel->next;
	}
}

int	ft_len_pile_a(t_control *control)
{
	int		nb;
	t_pile	*tmp;

	nb = 0;
	tmp = control->list_a;
	while (tmp)
	{
		tmp = tmp->next;
		nb++;
	}
	return (nb);
}

void	pre_sort(t_control *control)
{
	t_pile	*actuel;
	int		place;

	place = 0;
	sort_pile(control);
	actuel = control->list_a;
	while (actuel)
	{
		if (actuel->pos == -1)
		{
			ft_sort(control, place, 0);
			place++;
			actuel = control->list_a;
		}
		else
			actuel = actuel->next;
	}
	ft_doublon(control);
}
