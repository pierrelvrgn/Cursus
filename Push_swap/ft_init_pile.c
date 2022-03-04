/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:54:16 by plavergn          #+#    #+#             */
/*   Updated: 2022/02/23 13:24:34 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	exit_error(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

int	ft_check_variable(char *str)
{
	int		i;
	char	*base;
	int		a;
	int		j;
	int		nb;

	base = "0123456789";
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		a = 0;
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				a = 1;
			j++;
		}
		if (a == 0)
			exit_error();
		i++;
	}
	nb = ft_atoi(str);
	return (nb);
}

void	ft_doublon(t_control *control)
{
	t_pile	*actuel;
	t_pile	*temp;

	actuel = control->list_a;
	temp = control->list_a;
	while (actuel)
	{
		while (temp)
		{
			if (actuel->nb == temp->nb && temp->pos != actuel->pos)
				exit_error();
			temp = temp->next;
		}
		temp = control->list_a;
		actuel = actuel->next;
	}
}

t_control	*init(t_control *control, int argc, char **argv)
{
	int		i;
	char	**str;
	int		j;

	i = 1;
	control = ft_new_control();
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			ft_add_next(control, ft_new_lst(ft_check_variable(str[j])));
			j++;
		}
		i++;
	}
	return (control);
}
