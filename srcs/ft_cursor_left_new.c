/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 12:05:43 by cledant           #+#    #+#             */
/*   Updated: 2016/08/20 12:38:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_cursor_left_new(t_env *env)
{
	int		i_col;
	char	*s;

	i_col = 0;
	if (env->cur_char == 2)
		return (1);
	if (env->cur_il->left != NULL)
		env->cur_il = env->cur_il->left;
	env->cur_char--;
	s = env->cur_il->content;
	if (s[0] == '\n')
	{
		ft_putstr_fd(env->vi, env->fd_tty);
		ft_putstr_fd(env->up, env->fd_tty);
		while (i_col <= env->col)
		{
			ft_putstr_fd(env->nd, env->fd_tty);
			i_col++;
		}
		while (env->buff[env->cur_buff - 1] == 0 && env->cur_buff % env->col != 0)
		{
			ft_putstr_fd(env->le, env->fd_tty);
			env->cur_buff--;
		}
		ft_putstr_fd(env->ve, env->fd_tty);
	}
	else if (env->cur_buff % env->col == 0)
	{
		ft_putstr_fd(env->vi, env->fd_tty);
		ft_putstr_fd(env->up, env->fd_tty);
		while (i_col <= env->col)
		{
			ft_putstr_fd(env->nd, env->fd_tty);
			i_col++;
		}
		ft_putstr_fd(env->ve, env->fd_tty);
	}
	else
		ft_putstr_fd(env->le, env->fd_tty);
	env->cur_buff--;
	return (1);
}
