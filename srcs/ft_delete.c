/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:41:47 by cledant           #+#    #+#             */
/*   Updated: 2016/08/10 18:00:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_delete(t_env *env)
{
	size_t	bak;

	if (env->cur_char == env->last_char)
		return (1);
	bak = env->cur_char;
	ft_delete_cur_prompt(env);
	env->cur_char = bak;
	ft_btree_delete_node(env);
	ft_putstr_fd(env->vi, env->fd_tty);
	write(env->fd_tty, "$>", 2);
	if (env->last->content != NULL)
		ft_btree_wputstr_fd(env->last->content, env->fd_tty);
	ft_putstr_fd(env->ve, env->fd_tty);
	ft_cursor_moveback_to_cur(env);
	return (1);
}
