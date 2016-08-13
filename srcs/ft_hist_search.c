/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:03:04 by cledant           #+#    #+#             */
/*   Updated: 2016/08/13 15:50:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_hist_search(t_env *env, int where)
{
	t_btree		*previous;

	if (where == 0)
	{
		if (env->cur->left == NULL)
			return (1);
		env->cur = env->cur->left;
	}
	else
	{
		if (env->cur->right == NULL || env->cur->right == env->last)
			return (1);
		env->cur = env->cur->right;
	}
	previous = env->last->left;
	ft_delete_cur_prompt(env);
	if (env->last->left != NULL)
		env->last->left->right = NULL;
	ft_hist_destroy(&(env->last));
	if ((env->last = ft_btree_cpy_cur(previous, env)) == NULL)
		ft_handler(20000);
	write(env->fd_tty, "$>", 2);
	ft_btree_wputstr_fd(env->last->content, env->fd_tty);
	if (env->cur_char % env->col == 0)
		write(env->fd_tty, "\n", 1);
	return (1);
}
