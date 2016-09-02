/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:19:50 by cledant           #+#    #+#             */
/*   Updated: 2016/08/26 00:43:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_set_copy(t_env *env, int cut)
{
	int		len;

	if (env->cur_char == 2 || env->cur_char == env->last_char)
		env->end_copy = env->cur_il;
	else
		env->end_copy = env->cur_il->right;
	len = env->begin_cur_char - env->cur_char;
	if (env->cpy != NULL)
	{
		ft_btree_clear_content(&env->cpy);
		env->cpy = NULL;
	}
	if ((env->cpy = ft_btree_set_copy_paste(env->begin_copy, env->end_copy,
					len)) == NULL)
		ft_handler(20000);
	if (cut == 1)
	{
		ft_btree_cut_nodes(env, len);
		ft_reset_copy(env, 0);
	}
	else
		ft_reset_copy(env, 1);
	ft_set_pos_col(env);
//	if (env->cur_il == env->last->content && env->cur_buff == 3)
//		env->cur_buff = 2;
	return (1);
}
