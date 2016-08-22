/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 11:22:39 by cledant           #+#    #+#             */
/*   Updated: 2016/08/22 12:15:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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
