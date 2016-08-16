/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_set_copy_paste.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:52:37 by cledant           #+#    #+#             */
/*   Updated: 2016/08/16 12:48:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_btree		*ft_btree_set_copy_paste(t_btree *first, int len)
{
	size_t		sign;
	size_t		c;
	t_btree		*new;

	sign = (len < 0) ? 0 : 1;
	len = (len < 0) ? -len : len;
	new = NULL;
	while (c < len)
	{
		if ((new = ft_btree_pushback_cpy_pasta_node(first, new, sign, env))
				== NULL)
			return (NULL);
		first = (sign == 0) ? first->right : first->left;
		c++;
	}
	return (new);
}
