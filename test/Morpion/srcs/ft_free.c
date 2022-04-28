/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:20:39 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/28 11:21:08 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/morpion.h"

void	ft_free_all(t_list *list, char **board)
{
	int	index;

	index = 0;
	while (index < list->max_height)
	{
		free(board[index]);
		index++;
	}
	free(board);
	board = NULL;
	free(list);
	list = NULL;
}

char	**ft_free(char **board, int index, t_list *list)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(board[i]);
		i++;
	}
	free(board);
	board = NULL;
	free(list);
	return (board);
}
