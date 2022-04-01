/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:50:44 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/23 10:10:28 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*
Includes
*/

# include "libft/libft.h"
# include <stdlib.h>
# include <stdlib.h>
# include <stdio.h>

/*
Chained list
*/

typedef struct s_pile
{
	int				nb;
	struct s_pile	*next;
	int				pos;
}				t_pile;

typedef struct s_control
{
	t_pile	*list_a;
	t_pile	*list_b;
}				t_control;

/*
Prototypes
*/

void		exit_error(void);
void		ft_doublon(t_control *control);
t_control	*ft_new_control(void);
t_pile		*ft_new_lst(int content);
void		pre_sort(t_control *control);
t_control	*init(t_control *control, int argc, char **argv);
void		ft_add_next(t_control *control, t_pile *new);
void		print_list(t_control *control);
t_control	*init(t_control *control, int argc, char **argv);
void		ft_check_len(t_control *control);
void		ft_algo_500(t_control *control);
int			ft_is_sort(t_control *control, int len);
int			ft_len_pile_a(t_control *control);
void		ft_sort_3(t_control *control, int tab[]);
void		ft_rotate_a(t_control *control);
void		ft_push_a(t_control *control);
void		ft_push_b(t_control *control);
void		ft_sort_5(t_control *control);;
void		ft_swap_a(t_control *control);
void		ft_reverse_rotate_a(t_control *control);

/*
Define
*/

# define BASE "0123456789"

#endif
