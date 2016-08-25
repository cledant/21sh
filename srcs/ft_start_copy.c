/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:13:52 by cledant           #+#    #+#             */
/*   Updated: 2016/08/25 22:24:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_start_copy(t_env *env)
{
	if (env->cur_il->content == NULL)
		return (1);
	env->mode_copy = 1;
	env->begin_cur_char = env->cur_char;
	if (env->cur_char == env->last_char)
		ft_cursor_left_buff(env);
	if (env->cur_char == 2 || env->cur_char == env->last_char)
		env->begin_copy = env->cur_il;
	else
		env->begin_copy = env->cur_il->right;
	ft_putstr_fd(env->vi, env->fd_tty);
	return (1);
}
