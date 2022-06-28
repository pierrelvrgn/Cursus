/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:01:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/26 09:53:15 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSING_H
# define MINI_PARSING_H

# include <minishell.h>
# include <mini_built_in.h>
# include <mini_defines.h>
# include <mini_execution.h>
# include <mini_init.h>
# include <mini_managers.h>
# include <mini_messages.h>
# include <mini_prompt.h>
# include <mini_structs.h>

/*/////////////////////////////////////////////////////////////////////////////
		PARSING FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- case_redir_2.c --------------------*/

char	*test_split(char *split, char *str, int *tab_index);
int		*next_arg(char *str, int *tab_index, char c);
int		*init_tab_index(void);
int		*next_arg_base_fd(int *tab_index, char *str);

/*-------------------- case_redir.c --------------------*/

char	**redir_alone(char *str, t_cmd *cmd);
char	**redir_double(char *str, t_cmd *cmd);
char	**redir_fd(char *str, t_cmd *cmd);
char	**redir_double_fd(char *str, t_cmd *cmd);

/*-------------------- check_pre_sort.c --------------------*/

int		pipe_check(char *str, char *dest, int *tab_index, t_master *master);
int		check_base_fd(char *str, int i);
int		skip_redir(char *str, int i, int *tab_index);
int		redir_check(char *str, char *dest, int *tab_index, t_master *master);
int		end_check(char *str, char *dest, int *tab_index, t_master *master);

/*-------------------- norm.c --------------------*/

int		*ouioui(int *tab_index, char *str);
int		*test_norm(int *tab_index, char *str);
char	*init_split(char *str, int *tab_index);
int		skip_space(int i, char *str);
int		check_d_quote(char *str, int i);

/*-------------------- parsing_built_in.c --------------------*/

int		count_arg_echo(char *str);
char	*put_without_d_q(char *str, char *split, int len);
int		echo_n(char *str, int i);

/*-------------------- parsing_heredoc.c --------------------*/

char	*str_do(int i, char *line);
char	*check_char(char *line);

/*-------------------- parsing_main.c --------------------*/

int		mini_loop_quote(char *line, char quote, int a);
int		mini_check_supported_char(char *line, int a);
int		mini_check_syntax(char *line, char symbol, int a);
int		mini_check_line(char *line);

/*-------------------- parsing_norm.c --------------------*/

int		init_cmd(char *str, char *dest, t_master *master);
int		check_nb_dq(char *str);
char	*un_dblequote(char *str);
char	*pre_sort(char *str, t_master *master);

/*-------------------- parsing_redir.c --------------------*/

char	**tri_case(int *tab_case, char *str, t_cmd *cmd);
char	**find_case(char *str, t_cmd *cmd);

/*-------------------- parsing_redir.c --------------------*/

int		mini_jump_quote(char *str, int i);
int		mini_count_words_export(char *str);
char	*mini_get_split_part(char *str, int *i);
char	**split_export(char *str);

/*-------------------- parsing_test.c --------------------*/

char	**check_split_builtin(char *dest, char *str, t_cmd *cmd);
char	**check_split_cmd(char *str);
char	**check_type(char *dest, char *str, t_cmd *cmd);
void	init_cmd_no_redir(char *dest, t_master *master, t_cmd *cmd);
void	init_cmd_redir(char *dest, t_master *master, t_cmd *cmd);

/*-------------------- remove_all.c --------------------*/

// int	mini_check_spaces_heredoc(char *str, int i);
// char	*remove_heredoc(char *str);
// int	mini_check_spaces_fd_in(char *str, int i);
// char	*remove_fd_in(char *str);
char	*remove_all(char *str);

/*-------------------- split_built_in.c --------------------*/

char	**split_malloc(int nb);
char	**split_exit(char *str, char *dest, t_cmd *cmd);

/*-------------------- split_builtin.c --------------------*/

char	**split_pwd(char *dest);
char	**split_cd(char *str, char *dest, t_cmd *cmd);

/*-------------------- split_echo.c --------------------*/

// void	init_split_echo(t_cmd *cmd, char *dest, char *str, int j);
int		mini_increment_i(char *str, int i);
char	**split_echo(char *str, char *dest, t_cmd *cmd);

/*-------------------- token_id.c --------------------*/

int		check_builtin(char *split, int len_cmd);
int		check_token_id(char *split, int len_cmd);

/*-------------------- split_export.c --------------------*/

int		check_export(char *str, t_master *master, t_cmd *cmd);

#endif //MINI_PARSING_H
