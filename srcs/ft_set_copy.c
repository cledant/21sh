/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:19:50 by cledant           #+#    #+#             */
/*   Updated: 2016/08/24 16:09:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_set_copy(t_env *env)
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
	ft_reset_copy(env, 0);
//	ft_print_line(env);
	return (1);
}
