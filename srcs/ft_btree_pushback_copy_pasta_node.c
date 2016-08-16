/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_pushback_copy_pasta_node.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:31:01 by cledant           #+#    #+#             */
/*   Updated: 2016/08/16 16:55:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static t_btree		*ft_to_last(size_t sign, t_btree *cpy)
{
	if (sign == 0)
	{
		while(cpy->right != NULL)
			cpy = cpy->right;
	}
	else
	{
		while(cpy->left != NULL)
			cpy = cpy->left;
	}
	return (cpy);
}

static void			ft_link(size_t sign, t_btree *cpy, t_btree *new)
{
	if (sign == 0)
	{
		new->left = cpy;
		cpy->right = new;
	}
	else
	{
		new->right = cpy;
		cpy->left = new;	
	}
}

t_btree				*ft_btree_pushback_copy_pasta_node(t_btree *src,
						t_btree *cpy, size_t sign)
{
	t_btree		*new;
	t_btree		*first;
	
	if (cpy == NULL)
	{
		if ((first = ft_btree_new(src->content, 4)) == NULL)
			return (NULL);
	}
	else
	{
		first = cpy;
		cpy = ft_to_last(sign, cpy);
		if ((new = ft_btree_new(src->content, 4)) == NULL)
		{
			ft_btree_del_all_node(&first);
			return (NULL);
		}
		ft_link(sign, cpy, new);
		first = (sign == 0) ? first : new;
	}
	return (first);
}
