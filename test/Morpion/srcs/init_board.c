/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:12:46 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/28 11:21:04 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/morpion.h"

char	**init_board_variable(char **board, t_list *list)
{
	int	column;
	int	line;

	line = 0;
	column = 0;
	while (line < list->max_height)
	{
		while (column < list->max_width)
		{
			board[line][column] = SYMBOL_FOR_EMPTY;
			column++;
		}
		board[line][column] = '\0';
		column = 0;
		line++;
	}
	return (board);
}

char	**init_board(char **board, t_list *list)
{
	int	index;

	index = 0;
	board = malloc(sizeof(char *) * list->max_height);
	if (!board)
	{
		free(list);
		return (NULL);
	}
	while (index < list->max_width)
	{
		board[index] = malloc(sizeof(char) * (list->max_width + 1));
		if (!board[index])
		{
			board = ft_free(board, index, list);
			return (NULL);
		}
		index++;
	}
	board = init_board_variable(board, list);
	return (board);
}
