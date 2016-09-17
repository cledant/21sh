/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:17:44 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:48:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_reset_copy(t_env *env, size_t disp)
{
	env->mode_copy = 0;
	env->begin_cur_char = 0;
	env->begin_copy = NULL;
	env->end_copy = NULL;
	ft_bzero(env->inv_buff, env->last_buff);
	ft_putstr_fd(env->me, env->fd_tty);
	ft_putstr_fd(env->ve, env->fd_tty);
	if (disp == 1)
	{
		ft_move_cursor_from_cur_buff_to_before_prompt(env);
		ft_create_buffer(env);
		ft_print_buffer(env);
		ft_move_cursor_from_last_buff_to_cur_buff(env);
	}
	return (1);
}
