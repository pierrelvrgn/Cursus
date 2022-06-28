# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 15:59:54 by ljohnson          #+#    #+#              #
#    Updated: 2022/06/26 09:56:41 by ljohnson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re makelibft
.SILENT:

NAME			:=	minishell
LIBFT			:=	libft/libft.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

# Files
LST_HEAD		:=	minishell.h				mini_built_in.h			\
					mini_defines.h			mini_execution.h		\
					mini_init.h				mini_managers.h			\
					mini_parsing.h			mini_prompt.h			\
					mini_structs.h			mini_messages.h
LST_BUILT_IN	:=	built_in_cd.c			built_in_echo.c			\
					built_in_env.c			built_in_exit.c			\
					built_in_export.c		built_in_pwd.c			\
					built_in_unset.c
LST_EXECUTION	:=	exec_main.c				exec_redirection.c		\
					exec_built_in.c
LST_INIT		:=	init_master.c			init_envdata.c			\
					init_fdstruct.c
LST_MANAGERS	:=	manage_envdata_vars.c	manage_envdata_lst.c	\
					manage_execution.c		manage_expand.c
LST_PARSING		:=	parsing_heredoc.c		parsing_main.c			\
					parsing_test.c			parsing_built_in.c		\
					split_built_in.c		token_id.c				\
					check_pre_sort.c		parsing_redir.c			\
					case_redir_2.c			split_builtin.c			\
					parsing_norm.c			norm.c					\
					remove_all.c			split_echo.c			\
					case_redir.c			parsing_split_export.c	\
					split_export.c
LST_PROMPT		:=	prompt_heredoc.c		prompt_readline.c		\
					prompt_signal.c			check_prompt.c			\
					signal_child.c			checker_heredoc.c		\
					checker.c

# Directories
P_READLINE_LIB	:=	~/homebrew/opt/readline
P_HEAD_LIBFT	:=	libft/incs/
P_HEAD			:=	incs/
P_SRCS			:=	srcs/

P_BUILT_IN		:=	built_in/
P_EXECUTION		:=	execution/
P_INIT			:=	init/
P_MANAGERS		:=	managers/
P_PARSING		:=	parsing/
P_PROMPT		:=	prompt/

P_OBJS			:=	.objs/

# Shortcuts
INCS			:=	$(addprefix $(P_HEAD),$(LST_HEAD))
SRCS			:=	$(addprefix $(P_SRCS),main.c)							\
					$(addprefix $(P_SRCS)$(P_BUILT_IN),$(LST_BUILT_IN))		\
					$(addprefix $(P_SRCS)$(P_EXECUTION),$(LST_EXECUTION))	\
					$(addprefix $(P_SRCS)$(P_INIT),$(LST_INIT))				\
					$(addprefix $(P_SRCS)$(P_MANAGERS),$(LST_MANAGERS))		\
					$(addprefix $(P_SRCS)$(P_PARSING),$(LST_PARSING))		\
					$(addprefix $(P_SRCS)$(P_PROMPT),$(LST_PROMPT))
OBJS			:=	$(subst $(P_SRCS),$(P_OBJS),$(SRCS:.c=.o))

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

RLI	:=	-I $(P_READLINE_LIB)/include
RLL	:=	-L $(P_READLINE_LIB)/lib

CC	:=	gcc
CF	:=	-Wall -Wextra -Werror -g3 #-fsanitize=address
CI	:=	-I $(P_HEAD) -I $(P_HEAD_LIBFT)
CS	:=	-fsanitize=address
CG	:=	-g3
CL	:=	-lreadline

RM	:=	rm -rf

# Colors
BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m

# Text
ERASE=\033[2K\r
RESET=\033[0m
BOLD=\033[1m
FAINT=\033[2m
ITALIC=\033[3m
UNDERLINE=\033[4m

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all:	makelibft $(NAME)

# Binary creation
$(NAME): $(OBJS) $(INCS) $(LIBFT) Makefile
	$(CC) $(CF) $(RLL) $(CL) $(CI) $(LIBFT) $(OBJS) -o $@
	printf "\n$(GREEN)$(BOLD)Binary $(NAME) created$(RESET)	✅\n"

$(P_OBJS)%.o: $(P_SRCS)%.c $(INCS) $(LIBFT) Makefile | $(P_OBJS)
	$(CC) $(CF) $(CI) $(RLI) -c $< -o $@
	printf "$(ERASE)$(FAINT)$(CC) $(CF) $(CI) $(RLI) -c -o $(RESET)$(CYAN)$(BOLD)$@$(RESET) $(FAINT)$(BLUE)$<$(RESET)"

$(P_OBJS):
	mkdir -p $(P_OBJS)	\
	$(P_OBJS)$(P_BUILT_IN)	$(P_OBJS)$(P_EXECUTION)	\
	$(P_OBJS)$(P_INIT)		$(P_OBJS)$(P_MANAGERS)	\
	$(P_OBJS)$(P_PARSING)	$(P_OBJS)$(P_PROMPT)
	printf "$(GREEN)$(BOLD)Minishell obj directories created$(RESET)	✅\n"

# Libft creation
$(LIBFT): makelibft

makelibft:
	$(MAKE) -j 3 -C libft/

# Mandatory rules
clean:
	$(RM) $(OBJS)
	$(RM) $(P_OBJS)
	printf "$(YELLOW)$(BOLD)All Minishell object files removed$(RESET)\n"
	printf "$(YELLOW)$(BOLD)All Minishell object folders removed$(RESET)\n"

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft/
	printf "$(RED)$(BOLD)Binary $(NAME) removed $(RESET)\n"

re:
	$(MAKE) fclean
	$(MAKE) all
