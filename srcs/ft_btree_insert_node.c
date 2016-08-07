/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 17:09:05 by cledant           #+#    #+#             */
/*   Updated: 2016/08/07 18:32:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_btree		*ft_btree_insert_node(t_env *env, char s[4])
{
	t_btree		*new;

	if ((new = ft_btree_new(s, 4)) == NULL)
		return (NULL);
	new->left = env->cur_il;
	new->right = env->cur_il->right;
	new->right->left = new;
	new->left->right = new;
	if (env->cur_char == 2)
		env->last->content = new;
	return (new);
}
