/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morpion.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:31:33 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/28 11:20:56 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORPION_H
# define MORPION_H

/*
		INCLUDES
*/

# include <stdio.h>
# include <stdlib.h>

/*
		DEFINES
*/

# define SYMBOL_FOR_CROSS 'X'
# define SYMBOL_FOR_ZERO 'O'
# define SYMBOL_FOR_EMPTY ' '

/*
		STRUCTURES
*/

typedef struct	s_list
{
	int	max_height;
	int	max_width;
	int	current_turn;
	int	nb_2_win;
	int	play_bot;
}				t_list;

/*
		PROTOTYPES
*/

void	init_height_width(t_list *list);
void	init_nb_2_win(t_list *list);
void	init_play_bot(t_list *list);
t_list	*init_struct(t_list *list);
char	**init_board_variable(char **board, t_list *list);
char	**ft_free(char **board, int index, t_list *list);
char	**init_board(char **board, t_list *list);
void	ft_free_all(t_list *list, char **board);

#endif
