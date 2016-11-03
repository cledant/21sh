/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_right_node_error_quote.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:58:18 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:23:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_new_right_node_error_quote(t_env *env, int type)
{
	t_btree		*cont;

	if ((cont = ft_btree_new(NULL, 0)) == NULL)
		return (0);
	if (type == 1)
		env->err_quote = env->cur_il;
	env->last->content = cont;
	env->cur = env->last;
	env->cur_char = 2;
	env->last_char = 2;
	env->cur_il = cont;
	return (1);
}
