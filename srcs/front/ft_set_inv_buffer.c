/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 10:34:33 by cledant           #+#    #+#             */
/*   Updated: 2016/09/25 20:18:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline char		ft_set_state(t_env *env, t_btree *line, char state,
							t_btree *stop)
{
	if ((long int)(env->begin_cur_char - env->cur_char) == 0)
	{
		if (stop == line && env->begin_copy == line)
			state = (state == 0) ? 1 : 0;
	}
	else if ((long int)(env->begin_cur_char - env->cur_char) < 0)
	{
		if (stop->right == line || env->begin_copy == line)
			state = (state == 0) ? 1 : 0;
	}
	else
	{
		if (stop == line || env->begin_copy->right == line)
			state = (state == 0) ? 1 : 0;
	}
	return (state);
}

static inline void		ft_new_line(t_env *env, size_t *c, char state)
{
	size_t		first;

	first = 0;
	while (*c % env->col != 0)
	{
		if (first == 0)
			env->inv_buff[*c - 1] = state;
		else
			env->inv_buff[*c - 1] = 0;
		(*c)++;
		first++;
	}
}

static inline void		ft_add_tab(t_env *env, size_t *c, char state)
{
	size_t		counter;

	counter = 0;
	while (counter < TAB_LEN)
	{
		env->inv_buff[*c - 1] = state;
		(*c)++;
		counter++;
	}
	(*c)--;
}

static inline t_btree	*ft_set_stop(t_env *env)
{
	if (env->cur_char == 2 || env->cur_char == env->last_char)
		return (env->cur_il);
	else
		return (env->cur_il->right);
}

void					ft_set_inv_buffer(t_env *env)
{
	size_t		c;
	t_btree		*line;
	t_btree		*stop;
	char		*s;
	char		state;

	line = env->last->content;
	if (line->content == NULL)
		return ;
	c = 3;
	state = 0;
	stop = ft_set_stop(env);
	while (line != NULL)
	{
		s = line->content;
		state = ft_set_state(env, line, state, stop);
		if (s[0] == '\n')
			ft_new_line(env, &c, state);
		else if (s[0] == '\t')
			ft_add_tab(env, &c, state);
		else
			(env->inv_buff)[c - 1] = state;
		line = line->right;
		if ((env->begin_cur_char - env->cur_char) == 0)
			state = 0;
		c++;
	}
}
