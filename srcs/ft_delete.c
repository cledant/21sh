/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:41:47 by cledant           #+#    #+#             */
/*   Updated: 2016/08/12 01:37:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_delete(t_env *env)
{
	size_t	bak;

	if (env->cur_char == env->last_char && env->cur_char != 2)
		return (1);
	bak = env->cur_char;
	ft_delete_cur_prompt(env);
	env->cur_char = bak;
	ft_btree_delete_node(env);
	ft_putstr_fd(env->vi, env->fd_tty);
	write(env->fd_tty, "$>", 2);
	ft_btree_wputstr_fd(env->last->content, env->fd_tty);
	if (env->last_char % env->col == 0)
		write(env->fd_tty, "\n", 1);
	ft_putstr_fd(env->ve, env->fd_tty);
	ft_cursor_moveback_to_cur(env);
	return (1);
}
