/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:46:45 by cledant           #+#    #+#             */
/*   Updated: 2016/08/08 16:53:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_insert_char(char s[4], t_env *env)
{
	if (env->cur_char == env->last_char)
	{
		if ((env->cur_il = ft_btree_pushback_node(env->cur_il, s)) == NULL)
		{
			ft_hist_destroy(&(env->first));
			ft_handler(20000);
		}
	}
	else
	{
		if ((env->cur_il = ft_btree_insert_node(env, s)) == NULL)
		{
			ft_hist_destroy(&(env->first));
			ft_handler(20000);
		}
	}
	env->cur_char++;
	env->last_char++;
	env->cur = env->last;
}
