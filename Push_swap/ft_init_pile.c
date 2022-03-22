/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:54:16 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/22 08:20:08 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(char *str)
{
	printf("Error : %s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_check_variable(char *str)
{
	int		i;
	int		a;
	int		j;
	int		nb;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		a = 0;
		j = 0;
		while (BASE[j])
		{
			if (str[i] == BASE[j])
				a = 1;
			j++;
		}
		if (a == 0)
			exit_error(BAD_CHARACTER);
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
				exit_error(DOUBLON);
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
			free(str[j]);
			j++;
		}
		free(str);
		i++;
	}
	return (control);
}
