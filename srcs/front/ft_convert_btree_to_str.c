/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_btree_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:26:29 by cledant           #+#    #+#             */
/*   Updated: 2016/09/21 19:44:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_convert_btree_to_str(t_btree *root, size_t size)
{
	char	*str;
	char	*s;
	size_t	c;

	if ((str = ft_strnew(size)) == NULL)
		ft_handler(20000);
	c = 0;
	while (root != NULL)
	{
		s = root->content;
		str[c] = s[0];
		root = root->right;
		c++;
	}
	return (str);
}
