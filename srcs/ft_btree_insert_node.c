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

t_btree		*ft_btree_insert_node(t_btree *node, char s[4])
{
	char	*cpy;
	t_btree	*new;

	if (node->content == NULL)
	{
		if ((cpy = ft_memalloc(4)) == NULL)
			return (NULL);
		ft_memcpy(cpy, s, 4);
		node->content = cpy;
		node->content_size = 4;
		return (node);
	}
	else
	{
		if ((new = ft_btree_new(s, 4)) == NULL)
			return (NULL);
		new->left = node;
		node->right = new;
		return (new);
	}
}
