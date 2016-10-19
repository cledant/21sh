/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 20:49:14 by cledant           #+#    #+#             */
/*   Updated: 2016/10/19 19:03:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_main_shell(t_env *env)
{
	ft_putendl_fd_char2(env->env, env->fd_tty);
	ft_putendl_fd("=====", env->fd_tty);
	if (env->cmd_line != NULL)
		ft_putendl_fd(env->cmd_line, env->fd_tty);
	ft_putendl_fd("=====", env->fd_tty);
	if (env->cmd_line != NULL)
		ft_strdel(&(env->cmd_line));
	write(env->fd_tty, "$>", 2);
}
