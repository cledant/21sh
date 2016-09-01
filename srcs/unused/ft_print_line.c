/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 13:35:45 by cledant           #+#    #+#             */
/*   Updated: 2016/08/17 13:36:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_print_line(t_env *env)
{
	size_t	bak;
	size_t	c;
	t_btree	*list;

	bak = env->cur_char;
	ft_move_to_cur_prompt(env);
	env->cur_char = bak;
	write(env->fd_tty, "$>", 2);
	list = env->last->content;
	c = 2;
	while (list != NULL)
	{
		ft_wputchar_char_fd(list->content, env->fd_tty);
		list = list->right;
		c++;
	}
	ft_cursor_moveback_to_cur(env);
}
