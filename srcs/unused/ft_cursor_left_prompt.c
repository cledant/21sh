/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left_prompt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:15:29 by cledant           #+#    #+#             */
/*   Updated: 2016/08/12 01:20:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_cursor_left_prompt(t_env *env)
{
	int		i_col;

	i_col = 0;
	if (env->cur_char % env->col == 0)
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
	env->cur_char--;
}
