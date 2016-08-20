/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 10:34:33 by cledant           #+#    #+#             */
/*   Updated: 2016/08/19 16:43:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static inline void		ft_new_line(t_env *env, size_t *c)
{
	while (*c % env->col != 0)
	{
		env->buff[*c - 1] = 0;
		(*c)++;	
	}
}

static inline size_t	ft_calc_last_buff(t_env *env)
{
	t_btree		*line;
	size_t		c;
	char		*s;

	line = env->last->content;
	if (line->content == NULL)
		return (2);
	c = 2;
	while (line != NULL)
	{
		s = line->content;
		line = line->right;
		if (s[0] == '\n')
		{
			while (c % env->col != 0)
				c++;	
		}
		else
			c++;
	}
	return (c);
}

void					ft_create_buffer(t_env *env)
{
	size_t		c;
	t_btree		*line;
	char		*s;

	ft_bzero(env->buff, env->last_buff * sizeof(char));
	env->last_buff = ft_calc_last_buff(env);
	if (env->last_buff >= env->buff_size)
		ft_realloc_buff(env);
	line = env->last->content;
	ft_memcpy(env->buff, "$>", 2);
	env->cur_buff = 2;
	if (line->content == NULL)
		return ;
	c = 3;
	while (line != NULL)
	{
		s = line->content;
		if (s[0] == '\n')
			ft_new_line(env, &c);
		else
			(env->buff)[c - 1] = s[0];
		if (env->cur_il == line)
			env->cur_buff = c;
		line = line->right;
		c++;
	}
}
