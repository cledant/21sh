/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_set_copy_paste.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:52:37 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:09:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline int		ft_break(t_btree *first, t_btree *end, size_t sign)
{
	if (sign == 0)
	{
		if (first == end->right)
			return (1);
	}
	else
	{
		if (first == end->left)
			return (1);
	}
	return (0);
}

t_btree					*ft_btree_set_copy_paste(t_btree *first, t_btree *end,
		int len)
{
	size_t		sign;
	int			c;
	t_btree		*new;

	sign = (len < 0) ? 0 : 1;
	new = NULL;
	c = 0;
	while (1)
	{
		if ((new = ft_btree_pushback_copy_pasta_node(first, new, sign))
				== NULL)
			return (NULL);
		first = (sign == 0) ? first->right : first->left;
		if (ft_break(first, end, sign) == 1)
			break ;
	}
	return (new);
}
