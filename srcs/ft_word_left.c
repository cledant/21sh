/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 21:32:52 by cledant           #+#    #+#             */
/*   Updated: 2016/08/14 19:26:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static inline size_t	ft_seek_space(char *s, size_t type)
{
	if (ft_isspace(s[0]) == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0)
		type++;
	return (type);
}

static inline size_t	ft_seek_char(char *s, size_t type)
{
	if (ft_isspace(s[0]) == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0)
		return (type);
	type++;
	return (type);
}

static inline void		ft_move_cursor(t_env *env, size_t type, size_t dec,
							t_btree *seek)
{
	size_t	bak;

	if (type == 3)
	{
		bak = env->cur_char;
		ft_putstr_fd(env->vi, env->fd_tty);
		ft_cursor_move_to_end(env);
		ft_putstr_fd(env->ve, env->fd_tty);
		env->cur_char = bak - dec;
		env->cur_il = seek;
		ft_cursor_moveback_to_cur(env);
	}
	else if (type == 2 && seek == NULL &&
				ft_isspace((char)env->last->content) == 0)
	{
		bak = env->cur_char;
		ft_putstr_fd(env->vi, env->fd_tty);
		ft_cursor_move_to_end(env);
		ft_putstr_fd(env->ve, env->fd_tty);
		env->cur_char = 2;
		env->cur_il = env->last->content;
		ft_cursor_moveback_to_cur(env);
	}
}

int						ft_word_left(t_env *env)
{
	size_t		dec;
	size_t		type;
	t_btree		*seek;

	dec = 0;
	type = 0;
	seek = env->cur_il;
	if (env->cur_char == env->last_char && ft_seek_char(seek->content, type) == 1)
		type = 2;
	if (seek->content == NULL)
		return (1);
	while (seek != NULL)
	{
		if (type == 0)
			type = ft_seek_space(seek->content, type);
		else if (type == 1)
			type = ft_seek_char(seek->content, type);
		else if (type == 2)
			type = ft_seek_space(seek->content, type);
		if (type == 3)
			break ;
		dec++;
		seek = seek->left;
	}
	ft_move_cursor(env, type, dec, seek);
	return (1);
}
