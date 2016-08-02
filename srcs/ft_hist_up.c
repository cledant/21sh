/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:03:04 by cledant           #+#    #+#             */
/*   Updated: 2016/07/15 11:36:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_hist_up(t_env *env)
{
	t_btree		*previous;

	if (env->cur->left == NULL)
		return (1);
	env->cur = env->cur->left;
	previous = env->last->left;
//	ft_delete_cur_prompt(env);
	ft_putendl_fd("", env->fd_tty);
	ft_hist_destroy(&(env->last));
	if ((env->last = ft_btree_cpy_cur(previous, env)) == NULL)
		ft_handler(20000);
	write(env->fd_tty, "$>", 2);
	ft_btree_wputstr_fd(env->last->content, env->fd_tty);
	return (1);
}
