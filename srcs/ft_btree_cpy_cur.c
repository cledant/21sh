/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_cpy_cur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:52:17 by cledant           #+#    #+#             */
/*   Updated: 2016/08/06 17:52:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_btree		*ft_btree_cpy_cur(t_btree *previous, t_env *env)
{
	t_btree		*cpy;
	t_btree		*base;
	t_btree		*src;
	
	src = env->cur->content;
	cpy = NULL;
	env->cur_char = 0;
	if ((base = ft_btree_new(NULL, 0)) == NULL)
		return (NULL);
	while (src)
	{
		if ((cpy = ft_btree_pushback_cpy_node(src, cpy, env)) == NULL)
		{
			free(base);
			return (NULL);
		}
		src = src->right;
		env->cur_char++;
	}
	env->cur_char += 2;
	base->content = cpy;
	previous->right = base;
	base->left = previous;
	return (base);
}
