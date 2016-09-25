/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_clear_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 12:15:33 by cledant           #+#    #+#             */
/*   Updated: 2016/09/25 20:03:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
		prev = NULL;
	}
}
