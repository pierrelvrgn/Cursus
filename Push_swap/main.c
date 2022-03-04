/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:39:36 by plavergn          #+#    #+#             */
/*   Updated: 2022/02/24 10:36:44 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_control	*control;

	control = NULL;
	control = init(control, argc, argv);
	sort_0_to_100(control);
	print_list(control);
	exit(EXIT_SUCCESS);
}
