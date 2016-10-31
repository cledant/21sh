/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 18:33:53 by cledant           #+#    #+#             */
/*   Updated: 2016/10/31 19:15:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include "shell_struct.h"
# include "shell_init.h"
# include "shell_front.h"
# include "shell_key.h"
# include "shell_shell.h"
# include "shell_stack.h"

# ifndef SIGEMT
#  define SIGEMT 20000
# endif

# define TAB_LEN 4
# define STACK_INCREMENT 512

#endif
