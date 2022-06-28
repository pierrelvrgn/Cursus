/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_prompt.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:01:29 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/24 09:49:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PROMPT_H
# define MINI_PROMPT_H

# include <minishell.h>
# include <mini_built_in.h>
# include <mini_defines.h>
# include <mini_execution.h>
# include <mini_init.h>
# include <mini_managers.h>
# include <mini_messages.h>
# include <mini_parsing.h>
# include <mini_structs.h>

/*/////////////////////////////////////////////////////////////////////////////
		PROMPT FUNCTIONS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- check_prompt.c --------------------*/

void	check_str_empty(char *str);
void	check_exit_str(t_master *master);

/*-------------------- checker_heredoc.c --------------------*/

int		*check_heredoc(char *str, int *tab_index);
int		*check_herefile(char *str, int *tab_index);
int		check_access(char *arg, int heredoc);
int		mini_handle_heredoc(char *str, int *tab_index,
			char **arg, t_master *master);
int		mini_handle_fd_link(char *str, int *tab_index, char **arg);

/*-------------------- checker.c --------------------*/

char	*check_var(t_master *master, char *str);
int		check_space(char *str);
int		check_return(char *str);

/*-------------------- prompt_heredoc.c --------------------*/

int		mini_check_limiter(char *prompt, char *limiter);
void	norminette_src(char *prompt, char *str, int pipe_fd, t_master *master);
int		mini_heredoc(char *limiter, t_master *master);
int		ft_strlen_char(char *str, char c, int start);
int		start_heredoc(char *limiter, t_master *master);

/*-------------------- prompt_readline.c --------------------*/

int		ft_heredoc(char *str, t_master *master);
void	mini_exec_fd_link(t_master *master, int heredoc);
void	check_exit_str_1(char *str, t_master *master);
char	*norm_readline(t_master *master, char *str);
int		ft_readline(t_master *master);

/*-------------------- prompt_signal.c --------------------*/

void	ft_termios_handler(int end);
void	handler(int byte);
void	search_signal(void);

/*-------------------- signal_child.c --------------------*/

void	handler_here(int byte);
void	search_signal_heredoc(void);
void	handler_child(void);
void	handler_cat(int byte);

#endif //MINI_PROMPT_H
