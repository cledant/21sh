/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 11:22:39 by cledant           #+#    #+#             */
/*   Updated: 2016/08/15 20:00:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_btree_clear_content(t_btree **root)
{
	t_btree		*prev;

	while (*root != NULL)
	{
		if ((*root)->content != NULL)
			free((*root)->content);
		prev = *root;
		*root = (*root)->right;
		free(prev);
		prev= NULL;
	}
}

void			ft_hist_destroy(t_btree **root)
{
	t_btree		*previous;

	while (*root != NULL)
	{
		if ((*root)->content != NULL)
			ft_btree_clear_content((t_btree **)&(*root)->content);
		previous = *root;
		*root = (*root)->right;
		free(previous);
		previous = NULL;
	}
}
