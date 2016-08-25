/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_termsize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:55:08 by cledant           #+#    #+#             */
/*   Updated: 2016/08/25 15:19:41 by cledant          ###   ########.fr       */
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
	ft_reset_copy(env, 0);
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
}
