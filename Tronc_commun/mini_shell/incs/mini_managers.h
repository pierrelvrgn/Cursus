/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_managers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:00:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 14:39:41 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MANAGERS_H
# define MINI_MANAGERS_H

# include <minishell.h>
# include <mini_built_in.h>
# include <mini_defines.h>
# include <mini_execution.h>
# include <mini_init.h>
# include <mini_messages.h>
# include <mini_parsing.h>
# include <mini_prompt.h>
# include <mini_structs.h>

/*/////////////////////////////////////////////////////////////////////////////
		MANAGERS FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- manage_envdata_lst.c --------------------*/

void	*mini_get_env_var_by_index(t_envdata *envdata, int index);
void	mini_reset_env_list_index(t_envdata *envdata);
void	mini_set_env_list_index(t_envdata *envdata);
char	**mini_convert_lst_to_split(t_envdata *envdata);

/*-------------------- manage_envdata_vars.c --------------------*/

void	mini_delete_env_var(t_envdata *envdata, t_list *prev, t_list *current);
void	mini_append_env_var_value(t_envdata *envdata, char *name, char *value);
void	mini_change_env_var_value(t_envdata *envdata, char *name, char *value);
void	*mini_set_env_var(t_envdata *envdata, char *name, char *value);
void	*mini_get_env_var(t_envdata *envdata, char *name);

/*-------------------- manage_execution.c --------------------*/

int		mini_dup_handler(t_master *master, int pipe_fd[2], int last, int btin);
int		mini_close_child_process(int pipe_fd, int fd_link);
int		mini_check_cmd(char *cmd);
char	*mini_check_cmd_paths(char **paths, char *cmd);

/*-------------------- manage_expand.c --------------------*/

char	*mini_expand_global_var(char *line, int i);
char	*mini_create_new_line(t_env *env_var, char *line, int i);
char	*mini_get_varname(char *line, int i);
char	*mini_expand_env_var(t_envdata *envdata, char *line, int i);

#endif //MINI_MANAGERS_H