/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_defines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 07:59:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 07:54:53 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_DEFINES_H
# define MINI_DEFINES_H

# include <minishell.h>
# include <mini_built_in.h>
# include <mini_execution.h>
# include <mini_init.h>
# include <mini_managers.h>
# include <mini_messages.h>
# include <mini_parsing.h>
# include <mini_prompt.h>
# include <mini_structs.h>

/*/////////////////////////////////////////////////////////////////////////////
		DEFINES
*//////////////////////////////////////////////////////////////////////////////

# ifndef IDT_CMD
#  define IDT_CMD 10
# endif //IDT_CMD

# ifndef IDT_BTIN
#  define IDT_BTIN 20
# endif //IDT_BTIN

# ifndef IDT_REDIR
#  define IDT_REDIR 30
# endif //IDT_REDIR

# ifndef ENVNAME_CSET
#  define ENVNAME_CSET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_"
# endif //ENVNAME_CSET

#endif //MINI_DEFINES_H
