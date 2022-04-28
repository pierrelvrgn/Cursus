/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:46:02 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/20 14:25:55 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_control	*ft_new_control(void)
{
	t_control	*new;

	new = malloc(sizeof(t_control));
	new->list_a = NULL;
	new->list_b = NULL;
	return (new);
}

t_pile	*ft_new_lst(int content)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	new->next = NULL;
	new->nb = content;
	return (new);
}

void	ft_add_next(t_control *control, t_pile *new)
{
	t_pile	*temp;

	if (!control->list_a)
	{
		control->list_a = new;
		return ;
	}
	temp = control->list_a;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
