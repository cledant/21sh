/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:26:09 by cledant           #+#    #+#             */
/*   Updated: 2016/08/08 22:47:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_cursor_right(t_env *env)
{
	size_t	i_col;

	i_col = env->col;
	if (env->cur_char == env->last_char)
		return (1);
	if (env->cur_il->right != NULL)
		env->cur_il = env->cur_il->right;
	if (env->cur_char % env->col == env->col - 1)
		write(env->fd_tty, "\n", 1);
	else
		ft_putstr_fd(env->nd, env->fd_tty);
	env->cur_char++;
	return (1);
}
