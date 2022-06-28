/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:41:43 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/24 13:22:33 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_var
{
	int	k;
	int	i;
	int	c;
	int	tab[8];
}	t_var;

#endif
