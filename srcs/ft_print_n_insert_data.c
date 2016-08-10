/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_insert_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:42:37 by cledant           #+#    #+#             */
/*   Updated: 2016/08/10 17:59:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_print_n_insert_data(char s[4], t_env *env)
{
	size_t	bak;
	
	if (env->cur_char == env->last_char)
	{
		ft_wputchar_char_fd(s, env->fd_tty);
		ft_insert_char(s, env);
	}
	else
	{
		bak = env->cur_char;
		ft_putstr_fd(env->vi, env->fd_tty);
		ft_move_to_cur_prompt(env);
		env->cur_char = bak;
		ft_insert_char(s, env);
		write(env->fd_tty, "$>", 2);
		ft_btree_wputstr_fd(env->last->content, env->fd_tty);
		ft_putstr_fd(env->ve, env->fd_tty);
		ft_cursor_moveback_to_cur(env);
	}
}
