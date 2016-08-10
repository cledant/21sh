/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delete_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:37:30 by cledant           #+#    #+#             */
/*   Updated: 2016/08/10 17:51:37 by cledant          ###   ########.fr       */
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
	if (env->cur_il->right != NULL)
	{
		env->last->content = env->cur_il->right;
		env->cur_il = env->cur_il->right;
		env->cur_il->left = NULL;
	}
	else
		return ;
}

void					ft_btree_delete_node(t_env *env)
{
	t_btree		*del;

	if (env->cur_il->content == NULL)
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
	if (del->content != NULL)
	{
		free(del->content);
		del->content = NULL;
		if (env->cur_char != env->last_char)
		{
			env->last_char--;
			free(del);
		}
	}
}
