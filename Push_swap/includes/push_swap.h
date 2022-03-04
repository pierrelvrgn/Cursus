/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:50:44 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/01 13:41:10 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*
Includes
*/

# include "../libft/libft.h"
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
int			ft_check_variable(char *str);
t_control	*ft_new_control(void);
t_pile		*ft_new_lst(int content);
void		sort_0_to_100(t_control *control);
void		sort_pile(t_control *control);
t_control	*init(t_control *control, int argc, char **argv);
int			ft_atoi(const char *theString);
int			check(long long result, short sign);
void		ft_add_next(t_control *control, t_pile *new);
void		print_list(t_control *control);
t_control	*init(t_control *control, int argc, char **argv);
void		ft_sort(t_control *control, int place);

#endif
