/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_execution.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:00:13 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 07:54:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXECUTION_H
# define MINI_EXECUTION_H

# include <minishell.h>
# include <mini_built_in.h>
# include <mini_defines.h>
# include <mini_init.h>
# include <mini_managers.h>
# include <mini_messages.h>
# include <mini_parsing.h>
# include <mini_prompt.h>
# include <mini_structs.h>

/*/////////////////////////////////////////////////////////////////////////////
		EXECUTION FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- exec_built_in.c --------------------*/

int		mini_built_in_part_one(t_master *master, t_cmd *cmd);
int		mini_built_in_part_two(t_master *master, t_cmd *cmd, int a);
int		mini_btin_hub(t_master *master, t_cmd *cmd, int pipe_fd[2], int last);

/*-------------------- exec_main.c --------------------*/

int		mini_execve(t_envdata *envdata, t_cmd *cmd);
int		mini_exec_hub(t_master *master, t_cmd *cmd, int pipe_fd[2], int last);
int		mini_child_process(t_master *master, t_cmd *cmd, int last);
int		mini_wait_process(t_master *master);
int		mini_exec_loop(t_master *master);

/*-------------------- exec_redirection.c --------------------*/

int		mini_set_fd_in(t_cmd *cmd);
int		mini_set_fd_out(t_cmd *cmd, int slen, int last);
int		mini_redirect(void);
int		mini_redir_hub(t_cmd *cmd, int last);

#endif //MINI_EXECUTION_H