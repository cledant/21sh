/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_wputstr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 09:04:12 by cledant           #+#    #+#             */
/*   Updated: 2016/07/14 09:10:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_btree_wputstr_fd(t_btree *root, int fd)
{
	while (root != NULL)
	{
		if (root->content != NULL)
			ft_wputchar_char_fd(root->content, fd);
		root = root->right;
	}
}
