/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:46:02 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/22 15:14:49 by plavergn         ###   ########.fr       */
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

void	print_list(t_control *control)
{
	t_pile	*actuel;
	t_pile	*pileb;

	if (control == NULL)
	{
		exit(EXIT_FAILURE);
	}
	actuel = control->list_a;
	printf("Pile A : \n");
	while (actuel != NULL)
	{
		printf("Nb : %d     ||      ", actuel->nb);
		printf("Sort : %d\n", actuel->pos);
		actuel = actuel->next;
	}
	pileb = control->list_b;
	printf("Pile B : \n");
	while (pileb != NULL)
	{
		printf("Nb : %d     ||      ", pileb->nb);
		printf("Sort : %d\n", pileb->pos);
		pileb = pileb->next;
	}
	printf("NULL\n");
}

void	free_memory(t_control *control)
{
	t_pile		*tmp;
	t_pile		*clear;

	tmp = control->list_a;
	while (tmp)
	{
		clear = tmp;
		tmp = tmp->next;
		free(clear);
	}
}
