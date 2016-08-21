/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor_from_last_buff_to_cur_buff          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 13:22:13 by cledant           #+#    #+#             */
/*   Updated: 2016/08/21 13:27:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void		ft_max_left_to_nil(t_env *env)
{
	int		i_col;
	size_t	bak;

	bak = env->last_buff;
	while (bak > 0)
	{
		i_col = 0;
		if (bak % env->col == 0)
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
		bak--;
	}
}

void	ft_move_cursor_from_last_buff_to_cur_buff(t_env *env)
{
	size_t	counter;

	counter = 0;
	ft_putstr_fd(env->vi, env->fd_tty);
	ft_max_left_to_nil(env);
	while (counter < env->cur_buff)
	{
		if (counter % env->col == (unsigned int)(env->col - 1))
			write(env->fd_tty, "\n", 1);
		else
			ft_putstr_fd(env->nd, env->fd_tty);
		counter++;
	}
	ft_putstr_fd(env->ve, env->fd_tty);
}
