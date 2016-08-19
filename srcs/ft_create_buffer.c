/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 10:34:33 by cledant           #+#    #+#             */
/*   Updated: 2016/08/19 12:46:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static inline void	ft_new_line(t_env *env, size_t *c)
{
	while (*c % env->col != 0)
	{
		env->buff[*c - 1] = -1;
		(*c)++;	
	}
}

void				ft_create_buffer(t_env *env)
{
	size_t		c;
	t_btree		*line;
	size_t		new_size;

	env->last_buff = ft_calc_last_buff(env);
	if (env->last_buff >= env->buff_size)
		ft_realloc_buff(env);
	line = env->last->content;
	ft_memcpy(env->buff, "$>", 2);
	env->cur_buff = 2;
	if (line->content == NULL)
		return ;
	c = 2;
	while (line != NULL)
	{
		env->buff[c - 1] = (char *)(env->line->content)[0];
		if (env->line->content[0] == '\n')
			ft_new_line(env, &c);
		else
			c++;
		if (env->cur_il == line)
			env->cur_buff = c;
		line = line->right;
		c++;
	}
}
