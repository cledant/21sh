/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_backdelete_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 13:24:53 by cledant           #+#    #+#             */
/*   Updated: 2016/08/12 15:00:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static inline void		ft_del_first(t_env *env, t_btree *del)
{
	del->right->left = NULL;
	env->cur_il = del->right;
	env->last->content = del->right;
}

static inline void		ft_del(t_env *env, t_btree *del)
{
	del->right->left = del->left;
	del->left->right = del->right;
	env->cur_il = del->left;
}

static inline size_t	ft_del_last(t_env *env, t_btree *del)
{
	if (env->cur_char == 3)
		return (0);
	env->cur_il = del->left;
	env->cur_il->right = NULL;
	return (1);
}

void					ft_btree_backdelete_node(t_env *env)
{
	t_btree		*del;
	size_t		ret;

	ret = 1;
	del = env->cur_il;
	if (env->cur_char == env->last_char)
		ret = ft_del_last(env, del);
	else if (env->cur_char == 3)
		ft_del_first(env, del);
	else
		ft_del(env, del);
	free(del->content);
	del->content = NULL;
	if (ret == 1)
		free(del);
	env->last_char--;
	env->cur_char--;
}
