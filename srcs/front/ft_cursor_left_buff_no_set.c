/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left_buff_no_set.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 19:14:24 by cledant           #+#    #+#             */
/*   Updated: 2016/09/18 17:39:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_case_one(t_env *env, size_t *c)
{
	while (*c % env->col != (unsigned int)(env->col - 1))
	{
		ft_putstr_fd(env->nd, env->fd_tty);
		(*c)++;
	}
	ft_putchar_fd('\n', env->fd_tty);
	(*c)++;
}

static inline void		ft_case_two(t_env *env, size_t *c)
{
	size_t	counter;

	counter = 0;
	while (counter < TAB_LEN)
	{
		if (*c % env->col == (unsigned int)(env->col - 1))
			ft_putchar_fd('\n', env->fd_tty);
		else
			ft_putstr_fd(env->nd, env->fd_tty);
		(*c)++;
		counter++;
	}
}

static inline void		ft_case_three(t_env *env, size_t *c)
{
	if (*c % env->col == (unsigned int)(env->col - 1))
		ft_putchar_fd('\n', env->fd_tty);
	else
		ft_putstr_fd(env->nd, env->fd_tty);
	(*c)++;
}

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

int						ft_cursor_left_buff_no_set(t_env *env)
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
			ft_case_one(env, &c);
		else if (s[0] == '\t')
			ft_case_two(env, &c);
		else
			ft_case_three(env, &c);
		line = line->right;
	}
	env->cur_buff = c;
	env->pos_line = env->cur_buff / env->col;
	ft_putstr_fd(env->ve, env->fd_tty);
	return (1);
}
