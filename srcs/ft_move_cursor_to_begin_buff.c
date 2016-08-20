/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:13:14 by cledant           #+#    #+#             */
/*   Updated: 2016/08/20 19:12:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_move_cursor_to_begin_buff(t_env *env)
{
	int			i_col;
	size_t		cpy;

	cpy = env->cur_buff;
	while (cpy > 0)
	{
		i_col = 0;
		if (cpy % env->col == 0)
		{
			ft_putstr_fd(env->up, env->fd_tty);
			ft_putstr_fd(env->vi, env->fd_tty);
			while (i_col <= env->col)
			{
				ft_putstr_fd(env->nd, env->fd_tty);
				i_col++;
			}
			ft_putstr_fd(env->ve, env->fd_tty);
		}
		else
			ft_putstr_fd(env->le, env->fd_tty);
		cpy--;
	}
}
