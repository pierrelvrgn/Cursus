/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:10:38 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/28 11:48:01 by plavergn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/morpion.h"

/*
void	play(t_list *list, char **board)
{
}
*/

int	main(void)
{
	t_list	*list;
	char	**board;

	list = malloc(sizeof(t_list));
	if (!list)
		return (1);
	list = init_struct(list);
	board = init_board(board, list);
	if (!board)
		return (1);
	// play(list, board);
	ft_free_all(list, board);
	return (0);
}
