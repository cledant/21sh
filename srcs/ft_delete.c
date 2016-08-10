/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:41:47 by cledant           #+#    #+#             */
/*   Updated: 2016/08/10 13:03:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_delete(t_env *env)
{
	if (env->cur_char == env->last_char)
		return (1);
	ft_delete_cur_prompt(env);
	ft_btree_delete_node(env);
	ft_putstr_fd(env->vi, env->fd_tty);
	write(env->fd_tty, "$>", 2);
	ft_btree_wputstr_fd(env->last->content, env->fd_tty);
	ft_putstr_fd(env->ve, env->fd_tty);
	ft_cursor_moveback_to_cur(env);
	return (1);
}
