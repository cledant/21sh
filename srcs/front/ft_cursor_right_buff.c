/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_right_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 11:49:00 by cledant           #+#    #+#             */
/*   Updated: 2016/09/27 19:30:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_func_end(t_env *env, size_t c, t_btree *line,
							size_t flag)
{
	char	*s;

	if (flag == 1)
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
}

static inline void		ft_func_init(t_env *env, size_t *flag, size_t *c,
							t_btree **target)
{
	*flag = 0;
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	if (env->cur_char != 2)
		env->cur_il = env->cur_il->right;
	if (env->cur_il->right == NULL)
	{
		*flag = 1;
		*target = env->cur_il;
	}
	else
		*target = env->cur_il->right;
	env->cur_char++;
	*c = 2;
	ft_putstr_fd(env->vi, env->fd_tty);
	ft_putstr_fd(env->nd, env->fd_tty);
	ft_putstr_fd(env->nd, env->fd_tty);
}

int						ft_cursor_right_buff(t_env *env)
{
	t_btree		*line;
	t_btree		*target;
	size_t		c;
	char		*s;
	size_t		flag;

	if (env->cur_char == env->last_char)
		return (1);
	if ((env->cur_char == env->last_char - 1) && env->mode_copy == 1)
		return (1);
	ft_func_init(env, &flag, &c, &target);
	line = env->last->content;
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
	ft_func_end(env, c, line, flag);
	return (1);
}
