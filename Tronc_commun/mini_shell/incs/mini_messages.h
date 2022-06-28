/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_messages.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 07:51:39 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/24 08:15:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MESSAGES_H
# define MINI_MESSAGES_H

# include <minishell.h>
# include <mini_built_in.h>
# include <mini_defines.h>
# include <mini_execution.h>
# include <mini_init.h>
# include <mini_managers.h>
# include <mini_parsing.h>
# include <mini_prompt.h>
# include <mini_structs.h>

# define DFI	__FILE__
# define DLI	__LINE__
# define DFU	(char *)__FUNCTION__

# define E_ARG		"ERROR: No argument required"
# define E_ARG2		"ERROR: Too many arguments"
# define E_INVAL_ID	"ERROR: Not a valid identifier"

# define E_HOME		"ERROR: HOME not found"
# define E_OLDPWD	"ERROR: OLDPWD not found"
# define E_PATH		"ERROR: PATH not found"
# define E_CHDIR	"ERROR: Could not access file or directory"
# define E_GETCWD	"ERROR: getcwd command failed"
# define E_EXIT_NUM	"ERROR: Numeric Argument Required"

# define E_CLOSE	"ERROR: Close command failed"
# define E_DUP		"ERROR: Dup command failed"
# define E_DUP2		"ERROR: Dup2 command failed"
# define E_OPEN		"ERROR: Open command failed"
# define E_EXECVE	"ERROR: Execve command failed"
# define E_PIPE		"ERROR: Pipe command failed"
# define E_FORK		"ERROR: Fork command failed"
# define E_READ		"ERROR: Read command failed"
# define E_WRITE	"ERROR: Write command failed"
# define E_MALLOC	"ERROR: Malloc command failed"

# define E_ACCESS_F	"ERROR: File requested not found"
# define E_ACCESS_R	"ERROR: Permission read denied on file or directory"
# define E_ACCESS_W	"ERROR: Permission write denied on file or directory"
# define E_ACCESS_X	"ERROR: Permission execute denied on file or directory"

#endif //MINI_MESSAGES_H