/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 10:34:33 by cledant           #+#    #+#             */
/*   Updated: 2016/09/25 21:31:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_new_line(t_env *env, size_t *c)
{
	while (*c % env->col != 0)
	{
		env->buff[*c - 1] = 0;
		(*c)++;
	}
}

static inline void		ft_add_tab(t_env *env, size_t *c)
{
	size_t	counter;

	counter = 0;
	while (counter < TAB_LEN)
	{
		env->buff[*c - 1] = 0;
		(*c)++;
		counter++;
	}
	(*c)--;
}

static inline size_t	ft_calc_last_buff(t_env *env, t_btree *line)
{
	size_t		c;
	char		*s;
	size_t		c_rl;

	if (line->content == NULL)
		return (2);
	c = 2;
	c_rl = 0;
	while (line != NULL)
	{
		s = line->content;
		line = line->right;
		if (s[0] == '\n')
		{
			while (c % env->col != 0)
				c++;
			c_rl++;
		}
		else if (s[0] == '\t')
			c += TAB_LEN - 1;
		c++;
	}
	if (c_rl > 0)
		return (c - 1);
	return (c);
}

static inline void		ft_while(t_env *env, t_btree *line, size_t c)
{
	char	*s;

	while (line != NULL)
	{
		s = line->content;
		if (s[0] == '\n')
			ft_new_line(env, &c);
		else if (s[0] == '\t')
			ft_add_tab(env, &c);
		else
			(env->buff)[c - 1] = s[0];
		if (env->cur_il == line && env->cur_char == 2)
			env->cur_buff = 2;
		else if (env->cur_il == line)
			env->cur_buff = c;
		else if (env->mode_copy == 1 && env->cur_il == line)
			env->cur_buff = c - 1;
		line = line->right;
		c++;
	}
}

void					ft_create_buffer(t_env *env)
{
	size_t		c;
	t_btree		*line;

	ft_bzero(env->buff, env->last_buff * sizeof(char));
	ft_bzero(env->inv_buff, env->last_buff * sizeof(char));
	env->last_buff = ft_calc_last_buff(env, env->last->content);
	if (env->last_buff >= env->buff_size)
		ft_realloc_buff(env);
	line = env->last->content;
	ft_memcpy(env->buff, "$>", 2);
	env->cur_buff = 2;
	if (line->content == NULL)
		return ;
	c = 3;
	ft_while(env, line, c);
	if (env->mode_copy == 1)
		ft_set_inv_buffer(env);
}
