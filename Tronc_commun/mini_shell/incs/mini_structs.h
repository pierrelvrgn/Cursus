/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:01:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 07:55:38 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_STRUCTS_H
# define MINI_STRUCTS_H

# include <minishell.h>
# include <mini_built_in.h>
# include <mini_defines.h>
# include <mini_execution.h>
# include <mini_init.h>
# include <mini_managers.h>
# include <mini_messages.h>
# include <mini_parsing.h>
# include <mini_prompt.h>

/*/////////////////////////////////////////////////////////////////////////////
		TYPEDEF & STRUCT
*//////////////////////////////////////////////////////////////////////////////

int							g_mini_errno;
typedef struct s_master		t_master;

typedef struct s_fdstruct	t_fdstruct;

typedef struct s_envdata	t_envdata;
typedef struct s_env		t_env;

typedef struct s_execdata	t_execdata;
typedef struct s_cmd		t_cmd;

//master structure handling everything
struct s_master
{
	t_envdata	*envdata;
	t_execdata	*execdata;
	t_fdstruct	*fdstruct;
};

//main structure for fd handling
struct s_fdstruct
{
	int	fd_in;
	int	fd_out;
	int	fd_err;
	int	fd_link;
};

//main structure for env handling
struct s_envdata
{
	t_list	*lst;
	size_t	lst_size;
	void	*start;
	char	**paths;
};

//link of envdata->lst
struct s_env
{
	char	*name;
	char	*value;
	size_t	name_len;
	int		index;
};

//main structure for exec handling
struct s_execdata
{
	t_list	*lst;
	size_t	lst_size;
	void	*start;
};

//link of execdata->lst
struct s_cmd
{
	int		token_id;
	char	*raw;
	char	**split;
	int		len_cmd;
};

#endif //MINI_STRUCTS_H