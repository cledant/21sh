/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:46:45 by cledant           #+#    #+#             */
/*   Updated: 2016/09/21 19:56:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_insert_char(char s[4], t_env *env)
{
	if (env->cur_char == env->last_char && env->cur_il->content == NULL)
	{
		if ((env->cur_il->content = ft_memalloc(4)) == NULL)
			ft_handler(20000);
		ft_memcpy(env->cur_il->content, s, 4 * sizeof(char));
	}
	else if (env->cur_char == env->last_char && env->cur_il->content != NULL)
	{
		if ((env->cur_il = ft_btree_pushback_node(env->cur_il, s)) == NULL)
			ft_handler(20000);
	}
	else
	{
		if ((env->cur_il = ft_btree_insert_node(env, s)) == NULL)
			ft_handler(20000);
	}
	env->cur_char++;
	env->last_char++;
	env->cur = env->last;
}
