/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backdelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:57:48 by cledant           #+#    #+#             */
/*   Updated: 2016/08/12 13:24:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_backdelete(t_env *env)
{
	size_t	bak;

	if (env->cur_char == 2)
		return (1);
	bak = env->cur_char;
	ft_delete_cur_prompt(env);
	env->cur_char = bak;
	ft_btree_backdelete_node(env);
	ft_putstr_fd(env->vi, env->fd_tty);
	write(env->fd_tty, "$>", 2);
	ft_btree_wputstr_fd(env->last->content, env->fd_tty);
	if (env->last_char % env->col == 0)
		write(env->fd_tty, "\n", 1);
	ft_putstr_fd(env->ve, env->fd_tty);
	ft_cursor_moveback_to_cur(env);
	return (1);
}
