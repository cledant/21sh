/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor_from_cur_buff_to_before_pr          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 13:32:19 by cledant           #+#    #+#             */
/*   Updated: 2016/08/21 13:38:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_move_cursor_from_cur_buff_to_before_prompt(t_env *env)
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
