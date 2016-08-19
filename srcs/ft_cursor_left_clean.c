/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left_clean.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:00:23 by cledant           #+#    #+#             */
/*   Updated: 2016/08/19 15:10:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_cursor_left_clean(t_env *env)
{
	int		i_col;

	i_col = 0;
	if (env->cur_clean % env->col == 0)
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
	env->cur_clean--;
}
