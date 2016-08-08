/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 17:09:05 by cledant           #+#    #+#             */
/*   Updated: 2016/08/08 17:29:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_btree		*ft_btree_insert_node(t_env *env, char s[4])
{
	t_btree		*new;

	if ((new = ft_btree_new(s, 4)) == NULL)
		return (NULL);
	if (env->cur_char != 2)
	{
		new->left = env->cur_il;
		new->right = env->cur_il->right;
		new->right->left = new;
		new->left->right = new;
	}
	else
	{
		env->last->content = new;
		new->right = env->cur_il;
		env->cur_il->left = new;
	}
	return (new);
}
