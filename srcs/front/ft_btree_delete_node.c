/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delete_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:37:30 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:07:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_right_ok(t_env *env, t_btree *del)
{
	del->right->left = del->left;
	del->left->right = del->right;
	env->cur_il = del->left;
}

static inline void		ft_right_nok(t_env *env, t_btree *del)
{
	env->cur_il = del->left;
	env->cur_il->right = NULL;
}

static inline size_t	ft_change_first(t_env *env, t_btree *del)
{	
	if (del->right != NULL)
	{
		env->last->content = del->right;
		env->cur_il = del->right;
		env->cur_il->left = NULL;
		return (1);
	}
	return (0);
}

void					ft_btree_delete_node(t_env *env)
{
	t_btree		*del;
	size_t		ret;

	del = (env->cur_char != 2) ? env->cur_il->right : env->cur_il;
	if (del->content == NULL)
		return ;
	ret = 1;
	if (env->cur_char == 2)
		ret = ft_change_first(env, del);
	else
	{
		if (del->right == NULL)
			ft_right_nok(env, del);
		else
			ft_right_ok(env, del);
	}
	free(del->content);
	del->content = NULL;
	if (ret == 1)
		free(del);
	env->last_char--;
}
