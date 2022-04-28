/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:15:15 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/28 11:47:42 by plavergn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/morpion.h"

void	init_height_width(t_list *list)
{
	while(list->max_height < 3 || list->max_width < 3)
	{
		printf("Please input the height and the width of the board:\n");
		scanf("%d %d", &list->max_height, &list->max_width);
		if (list->max_height < 3 || list->max_width < 3)
			printf("Wrong input!\n");
	}
}

void	init_nb_2_win(t_list *list)
{
	while(list->nb_2_win < 1 || list->nb_2_win > list->max_height || list->nb_2_win > list->max_width)
	{
		printf("Please input the number of consecutive symbols to win:\n");
		scanf("%d",&list->nb_2_win);
		if (list->nb_2_win < 1 || list->nb_2_win > list->max_height || list->nb_2_win > list->max_width)
			printf("Wrong input!\n");
	}
}

void	init_play_bot(t_list *list)
{
	char	c;

	while (list->play_bot == -1)
	{
		if (c != '\n')
			printf("Do you want to play with a bot? Write ‘y’ for yes and ‘n’ for no:\n");
		scanf("%c", &c);
		if (c == 'y')
			list->play_bot = 1;
		else if (c == 'n')
			list->play_bot = 0;
		else if (c != '\n')
			printf("Wrong input!\n");
	}
}

t_list	*init_struct(t_list *list)
{
	list->current_turn = 0;
	list->max_width = 0;
	list->max_height = 0;
	list->nb_2_win = 0;
	list->play_bot = -1;
	init_height_width(list);
	init_nb_2_win(list);
	init_play_bot(list);
	return (list);
}
