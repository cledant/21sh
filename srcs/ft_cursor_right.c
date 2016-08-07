/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:26:09 by cledant           #+#    #+#             */
/*   Updated: 2016/08/07 18:31:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_cursor_right(t_env *env)
{
	size_t	i_col;

	i_col = env->col;
	if (env->cur_char == env->last_char)
		return (1);
	if (env->cur_il->right != NULL)
		env->cur_il = env->cur_il->right;
	if (env->cur_char % env->col == env->col)
	{
		ft_putstr_fd(env->doo, env->fd_tty);
		ft_putstr_fd(env->vi, env->fd_tty);
		while (i_col > 0)
		{
			ft_putstr_fd(env->le, env->fd_tty);
			i_col--;
		}
		ft_putstr_fd(env->ve, env->fd_tty);
	}
	else
		ft_putstr_fd(env->nd, env->fd_tty);
	env->cur_char++;
	return (1);
}
