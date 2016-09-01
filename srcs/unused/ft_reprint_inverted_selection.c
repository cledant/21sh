/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reprint_inverted_selection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 12:26:43 by cledant           #+#    #+#             */
/*   Updated: 2016/08/17 15:30:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_reprint_inverted_selection(t_env *env)
{
	size_t	bak;
	size_t	starter;
	size_t	end;
	size_t	c;
	t_btree	*list;

	bak = env->cur_char;
	ft_move_to_cur_prompt(env);
	env->cur_char = bak;
	if (env->begin_cur_char <= env->cur_char)
	{
		starter = env->begin_cur_char;
		end = env->cur_char;
		c = 3;
	}
	else
	{
		end = env->begin_cur_char;
		starter = env->cur_char;
		c = 2;
	}
	write(env->fd_tty, "$>", 2);
	list = env->last->content;

	while (list != NULL)
	{
		ft_wputchar_char_fd(list->content, env->fd_tty);
		if (c == starter)
			ft_putstr_fd(env->mr, env->fd_tty);
		if (c == end)
			ft_putstr_fd(env->me, env->fd_tty);
		list = list->right;
		c++;
	}
	ft_cursor_moveback_to_cur(env);
}
