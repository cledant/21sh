/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 20:49:14 by cledant           #+#    #+#             */
/*   Updated: 2016/11/13 16:35:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_debug_cmd(t_env *env, int nb_cmd)
{
	ft_putendl_fd("=====", env->fd_tty);
	if (env->cmd_line != NULL)
		ft_putendl_fd(env->cmd_line, env->fd_tty);
	ft_putendl_fd("=====", env->fd_tty);
	ft_putstr_fd("Nbre cmd : ", env->fd_tty);
	ft_putnbr_fd(nb_cmd, env->fd_tty);
	write(env->fd_tty, "\n", 1);
	ft_putendl_fd("=====", env->fd_tty);
}

void	ft_main_shell(t_env *env)
{
	int		nb_cmd;

	if (env->cmd_line == NULL)
		return ;
	if ((nb_cmd = ft_count_commands(env->cmd_line)) < 0)
	{
		ft_putendl_fd("21sh : parse error near ;;", env->fd_tty);
		ft_debug_cmd(env, nb_cmd);
		if (env->cmd_line != NULL)
			ft_strdel(&env->cmd_line);
		return ;
	}
	ft_debug_cmd(env, nb_cmd);
	if (env->cmd_line != NULL)
		ft_strdel(&env->cmd_line);
}
