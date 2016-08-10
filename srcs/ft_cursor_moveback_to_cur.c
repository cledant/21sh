/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_moveback_to_cur.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 18:19:35 by cledant           #+#    #+#             */
/*   Updated: 2016/08/10 10:52:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void		ft_max_left_to_nil(t_env *env)
{
	int		i_col;
	size_t	bak;

	bak = env->last_char;
	while (env->last_char > 0)
	{
		i_col = 0;
		if (env->last_char % env->col == 0)
		{
			ft_putstr_fd(env->up, env->fd_tty);
			while (i_col <= env->col)
			{
				ft_putstr_fd(env->nd, env->fd_tty);
				i_col++;
			}
		}
		else
			ft_putstr_fd(env->le, env->fd_tty);
		env->last_char--;
	}
	env->last_char = bak;
}

void	ft_cursor_moveback_to_cur(t_env *env)
{
	size_t	counter;

	counter = 0;
	ft_putstr_fd(env->vi, env->fd_tty);
	ft_max_left_to_nil(env);
	while (counter < env->cur_char)
	{
		if (counter % env->col == env->col - 1)
			write(env->fd_tty, "\n", 1);
		else
			ft_putstr_fd(env->nd, env->fd_tty);
		counter++;
	}
	ft_putstr_fd(env->ve, env->fd_tty);
}
