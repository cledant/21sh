/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_err_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:31:00 by cledant           #+#    #+#             */
/*   Updated: 2016/11/04 19:13:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_add_to_err_quote(t_env *env)
{
	t_btree		*cpy_err;
	t_btree		*cont;

	cpy_err = env->err_quote;
	while (cpy_err->right != NULL)
		cpy_err = cpy_err->right;
	cpy_err->right = env->last->content;
	cont = env->last->content;
	cont->left = cpy_err;
}
