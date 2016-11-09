/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:21:19 by cledant           #+#    #+#             */
/*   Updated: 2016/11/09 22:03:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_reset(t_env *env)
{
	ft_bzero(env->buff, env->last_buff);
	(env->err_quote == NULL) ? ft_memcpy(env->buff, "$>", 2) :
		ft_memcpy(env->buff, "*>", 2);
	env->cur_buff = 2;
	env->last_buff = 2;
	if (env->err_quote == NULL)
		ft_main_shell(env);
	(env->err_quote == NULL) ? write(env->fd_tty, "$>", 2) :
		write(env->fd_tty, "*>", 2);
}

int						ft_enter(t_env *env)
{
	char	enter[4];

	ft_bzero(&enter, 4);
	enter[0] = '\n';
	ft_move_cursor_from_cur_buff_to_end_buff(env);
	write(env->fd_tty, "\n", 1);
	if (env->cur_il->content != NULL)
		ft_enter_content_not_null(env);
	else if (env->err_quote == NULL)
		env->cur = env->last;
	else
	{
		ft_insert_char(enter, env);
		ft_add_to_err_quote(env);
		if (ft_new_right_node_error_quote(env, 0) != 1)
			ft_handler(20000);
	}
	ft_reset(env);
	return (1);
}
