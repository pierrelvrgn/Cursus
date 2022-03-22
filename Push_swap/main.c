/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:39:36 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/22 17:20:17 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_control	*control;

	control = NULL;
	control = init(control, argc, argv);
	pre_sort(control);
	ft_check_len(control);
//	free_memory(control);
	exit(EXIT_SUCCESS);
}
/*
*/
