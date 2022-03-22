/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:05:22 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/22 18:10:13 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_control *control)
{
	t_pile	*tmp;
	t_pile	*move;

	move = control->list_a;
	tmp = control->list_a;
	control->list_a = move->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = move;
	move->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	ft_push_a(t_control *control)
{
	t_pile	*tmp;

	tmp = control->list_b;
	if (!tmp)
		return ;
	if (!control->list_a)
	{
		control->list_b = tmp->next;
		control->list_a = tmp;
		tmp->next = NULL;
	}
	else
	{
		control->list_b = tmp->next;
		tmp->next = control->list_a;
		control->list_a = tmp;
	}
	ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_control *control)
{
	t_pile	*tmp;

	tmp = control->list_a;
	if (!tmp)
		return ;
	if (!control->list_b)
	{
		control->list_a = tmp->next;
		control->list_b = tmp;
		tmp->next = NULL;
	}
	else
	{
		control->list_a = tmp->next;
		tmp->next = control->list_b;
		control->list_b = tmp;
	}
	ft_putstr_fd("pb\n", 1);
}

void	ft_swap_a(t_control *control)
{
	t_pile	*pile_a;
	int		tmp;

	pile_a = control->list_a;
	tmp = pile_a->next->pos;
	pile_a->next->pos = pile_a->pos;
	pile_a->pos = tmp;
	control->list_a = pile_a;
	ft_putstr_fd("sa\n", 1);
}

void	ft_reverse_rotate_a(t_control *control)
{
	t_pile	*tmp;
	t_pile	*move;

	move = control->list_a;
	tmp = control->list_a;
	while (tmp->next)
		tmp = tmp->next;
	while (move->next->next)
		move = move->next;
	move->next = NULL;
	tmp->next = control->list_a;
	control->list_a = tmp;
	ft_putstr_fd("rra\n", 1);
}
