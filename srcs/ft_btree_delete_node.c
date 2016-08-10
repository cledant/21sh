/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delete_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:37:30 by cledant           #+#    #+#             */
/*   Updated: 2016/08/10 13:30:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"


static inline void		ft_right_ok(t_env *env)
{
	env->cur_il->right->left = env->cur_il->left;
	env->cur_il->left->right = env->cur_il->right;
	env->cur_il = env->cur_il->right;
}

static inline void		ft_right_nok(t_env *env)
{
	env->cur_il = env->cur_il->left;
	env->cur_il->left = NULL;
}

static inline void		ft_change_first(t_env *env)
{
	env->last->content = env->cur_il->right;
	env->cur_il = env->cur_il->right;
	env->cur_il->left = NULL;
}

void					ft_btree_delete_node(t_env *env)
{
	t_btree		*del;

	if (env->cur_char == env->last_char)
		return ;
	del = env->cur_il;
	if (env->cur_char == 2)
		ft_change_first(env);
	else
	{
		if (env->cur_il->right == NULL)
			ft_right_nok(env);
		else
			ft_right_ok(env);
	}
	env->last_char--;
	free(del->content);
	free(del);
}
