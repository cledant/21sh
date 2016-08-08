/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_move_to_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:25:47 by cledant           #+#    #+#             */
/*   Updated: 2016/08/08 13:33:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_cursor_move_to_end(t_env *env)
{
	int		count;

	count = 0;
	while (env->last_char != env->cur_char)
	{
		if (env->cur_char % env->col == 0)
		{
			ft_putstr_fd(env->doo, env->fd_tty);
			while (count > env->col)
			{
				ft_putstr_fd(env->le, env->fd_tty);
				count++;
			}
			count = 0;
		}
		else
			ft_putstr_fd(env->nd, env->fd_tty);
		env->cur_char++;
		if (env->cur_il->right != NULL)
			env->cur_il = env->cur_il->right;
	}
	return (1);
}
