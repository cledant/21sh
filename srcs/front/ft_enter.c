/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:21:19 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:14:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_enter(t_env *env)
{
	ft_move_cursor_from_cur_buff_to_end_buff(env);
	write(env->fd_tty, "\n", 1);
	if (env->cur_il->content != NULL)
	{
		ft_btree_wputendl_fd(env->last->content, env->fd_tty);
		if ((env->last = ft_new_right_node(env)) == NULL)
		{
			ft_hist_destroy(&(env->first));
			ft_handler(20000);
		}
	}
	else
		env->cur = env->last;
	ft_bzero(env->buff, env->last_buff);
	ft_memcpy(env->buff, "$>", 2);
	env->cur_buff = 2;
	env->last_buff = 2;
	ft_print_buffer(env);
	return (1);
}
