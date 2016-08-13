/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_termsize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:55:08 by cledant           #+#    #+#             */
/*   Updated: 2016/08/13 17:19:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_change_termsize(t_env *env)
{
	struct winsize	size;

	if (ioctl(0, TIOCGWINSZ, &size) == -1)
		ft_handler(20000);
	env->col = size.ws_col;
	env->line = size.ws_row;
	ft_putstr_fd(env->ho, env->fd_tty);
	ft_putstr_fd(env->cl, env->fd_tty);
	write(env->fd_tty, "$>", 2);
	ft_btree_wputstr_fd(env->last->content, env->fd_tty);
	if (env->cur_char != env->last_char)
		ft_cursor_moveback_to_cur(env);
}
