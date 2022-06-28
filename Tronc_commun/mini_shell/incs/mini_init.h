/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_init.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:00:35 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 07:55:17 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_INIT_H
# define MINI_INIT_H

# include <minishell.h>
# include <mini_built_in.h>
# include <mini_defines.h>
# include <mini_execution.h>
# include <mini_managers.h>
# include <mini_messages.h>
# include <mini_parsing.h>
# include <mini_prompt.h>
# include <mini_structs.h>

/*/////////////////////////////////////////////////////////////////////////////
		INIT FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- init_envdata.c --------------------*/

int	mini_init_paths(t_envdata *envdata);
int	mini_init_env_var(t_envdata *envdata, char *envline);
int	mini_init_base_vars(t_envdata *envdata);
int	mini_init_envdata(t_envdata *envdata, char **env);

/*-------------------- init_fdstruct.c --------------------*/

int	mini_reset_fdstruct(t_fdstruct *fdstruct);
int	mini_close_fdstruct(t_fdstruct *fdstruct);
int	mini_init_fdstruct(t_fdstruct *fdstruct);

/*-------------------- init_master.c --------------------*/

int	mini_init_master(t_master *master, char **env);

#endif //MINI_INIT_H