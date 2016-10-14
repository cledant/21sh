/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:21:19 by cledant           #+#    #+#             */
/*   Updated: 2016/10/14 21:22:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_create_n_display_str(t_env *env)
{
	if (env->cmd_line != NULL)
		ft_strdel(&(env->cmd_line));
	if ((env->cmd_line = ft_convert_btree_to_str(env->last->content,
			env->last_char)) == NULL)
		ft_handler(20000);
}

int						ft_enter(t_env *env)
{
	ft_move_cursor_from_cur_buff_to_end_buff(env);
	write(env->fd_tty, "\n", 1);
	if (env->cur_il->content != NULL)
	{
		ft_create_n_display_str(env);
		if ((env->last = ft_new_right_node(env)) == NULL)
			ft_handler(20000);
	}
	else
		env->cur = env->last;
	ft_bzero(env->buff, env->last_buff);
	ft_memcpy(env->buff, "$>", 2);
	env->cur_buff = 2;
	env->last_buff = 2;
	ft_main_shell(env);
	return (1);
}
