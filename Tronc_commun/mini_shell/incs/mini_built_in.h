/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_built_in.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 07:59:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 07:54:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BUILT_IN_H
# define MINI_BUILT_IN_H

# include <minishell.h>
# include <mini_defines.h>
# include <mini_execution.h>
# include <mini_init.h>
# include <mini_managers.h>
# include <mini_messages.h>
# include <mini_parsing.h>
# include <mini_prompt.h>
# include <mini_structs.h>

/*/////////////////////////////////////////////////////////////////////////////
		BUILT_IN FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- built_in_cd.c --------------------*/

int		mini_chdir_home(t_envdata *envdata, char *path, char *old_pwd);
int		mini_chdir_oldpwd(t_envdata *envdata, char *old_pwd);
int		mini_check_path(t_envdata *envdata, char *pwd, char *path);
int		mini_cd_built_in(t_envdata *envdata, char *path);

/*-------------------- built_in_echo.c --------------------*/

int		mini_echo_built_in(char **split);

/*-------------------- built_in_env.c --------------------*/

int		mini_env_built_in(t_envdata *envdata, t_cmd *cmd);

/*-------------------- built_in_exit.c --------------------*/

// int	mini_check_raw_arg(char *raw_arg);
int		mini_exit_built_in(t_master *master, char *raw_arg);

/*-------------------- built_in_export.c --------------------*/

int		mini_export_display(t_envdata *envdata);
void	mini_add_var(t_envdata *envdata, char *arg, int append);
// int	mini_check_raw_arg(char *raw_arg);
int		mini_export_built_in(t_envdata *envdata, char *raw_arg);

/*-------------------- built_in_pwd.c --------------------*/

int		mini_pwd_built_in(void);

/*-------------------- built_in_unset.c --------------------*/

// int	mini_check_raw_arg(char *raw_arg);
int		mini_unset_built_in(t_envdata *envdata, char *raw_arg);

#endif //MINI_BUILT_IN_H
