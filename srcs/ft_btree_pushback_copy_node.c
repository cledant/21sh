/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_pushback_copy_node.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:52:13 by cledant           #+#    #+#             */
/*   Updated: 2016/08/12 16:27:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_btree		*ft_btree_pushback_cpy_node(t_btree *src, t_btree *cpy, t_env *env)
{
	t_btree		*new;
	t_btree		*first;
	

	if (cpy == NULL)
	{
		if ((first = ft_btree_new(src->content, 4)) == NULL)
			return (NULL);
		env->cur_il = first;
	}
	else
	{
		first = cpy;
		while(cpy->right != NULL)
			cpy = cpy->right;
		if ((new = ft_btree_new(src->content, 4)) == NULL)
		{
			ft_btree_del_all_node(&first);
			return (NULL);
		}
		env->cur_il = new;
		new->left = cpy;
		cpy->right = new;
	}
	return (first);
}
