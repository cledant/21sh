/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 09:21:04 by cledant           #+#    #+#             */
/*   Updated: 2016/07/14 11:38:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_btree		*ft_btree_insert_node(t_btree *node, char s[4], size_t size)
{
	char	*cpy;
	t_btree	*new;

	if (node->content == NULL)
	{
		if ((cpy = ft_memalloc(4)) == NULL)
			return (NULL);
		ft_memcpy(cpy, s, 4);
		node->content = cpy;
		if ((new = ft_btree_new(NULL, 0)) == NULL)
			return (NULL);
		node->right = new;
		return (new);
	}
	else
	{
		if ((new = ft_btree_new(s, 4)) == NULL)
			return (NULL);
		new->right = node;
		new->left = node->left;
		node->left = new;
		return (node);
	}
}
