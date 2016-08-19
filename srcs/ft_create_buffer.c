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
		env->buff[*c - 1] = -1;
		(*c)++;	
	}
}

static inline size_t	ft_calc_last_buff(t_env *env)
{
	t_btree		*line;
	size_t		c;

	line = env->last->content;
	if (line->content == NULL)
		return (2);
	c = 2;
	while (line != NULL)
	{
		if ((char)(line->content) == '\n')
		{
			while (c % env->col != 0)
				c++;	
		}
		else
			c++;
		line = line->right;
		c++;
	}
	return (c);
}

void					ft_create_buffer(t_env *env)
{
	size_t		c;
	t_btree		*line;

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
		(env->buff)[c - 1] = ((char)(line->content));
		if ((char)(line->content) == '\n')
			ft_new_line(env, &c);
		else
			c++;
		if (env->cur_il == line)
			env->cur_buff = c;
		line = line->right;
		c++;
	}
}
