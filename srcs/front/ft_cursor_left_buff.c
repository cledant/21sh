/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left_buff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 19:14:24 by cledant           #+#    #+#             */
/*   Updated: 2016/09/27 19:14:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_init(t_env *env, size_t *c, t_btree **target,
							t_btree **line)
{
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	*target = env->cur_il;
	if (env->cur_il->left != NULL)
		env->cur_il = env->cur_il->left;
	*line = env->last->content;
	env->cur_char--;
	*c = 2;
	ft_putstr_fd(env->vi, env->fd_tty);
	ft_putstr_fd(env->nd, env->fd_tty);
	ft_putstr_fd(env->nd, env->fd_tty);
}

int						ft_cursor_left_buff(t_env *env)
{
	t_btree		*line;
	t_btree		*target;
	size_t		c;
	char		*s;

	if (env->cur_char == 2)
		return (1);
	ft_init(env, &c, &target, &line);
	while (line != target)
	{
		s = line->content;
		if (s[0] == '\n')
			ft_cursor_case_one(env, &c);
		else if (s[0] == '\t')
			ft_cursor_case_two(env, &c);
		else
			ft_cursor_case_three(env, &c);
		line = line->right;
	}
	env->cur_buff = c;
	ft_set_pos_col(env);
	ft_putstr_fd(env->ve, env->fd_tty);
	return (1);
}
