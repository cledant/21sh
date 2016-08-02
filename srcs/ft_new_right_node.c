/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_right_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:58:18 by cledant           #+#    #+#             */
/*   Updated: 2016/07/14 12:07:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_btree		*ft_new_right_node(t_env *env)
{
	t_btree		*new;
	t_btree		*cont;

	if ((new = ft_btree_new(NULL, 0)) == NULL)
		return (NULL);
	if ((cont = ft_btree_new(NULL, 0)) == NULL)
	{
		free(new);
		return (NULL);
	}
	new->content = cont;
	env->last->right = new;
	new->left = env->last;
	env->last = new;
	env->cur = env->last;
	env->cur_char = 2;
	env->cur_il = cont;
	return (new);
}
