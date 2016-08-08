/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_moveback_to_cur.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:11:53 by cledant           #+#    #+#             */
/*   Updated: 2016/08/08 15:13:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_cursor_moveback_to_cur(t_env *env)
{
	size_t	c;
	int		count;
	size_t	cpy_cc;

	c = 0;
	count = 0;
	cpy_cc = env->last_char;
	while (c < env->last_char - env->cur_char)
	{
		if (cpy_cc % env->col == 0)
		{
			ft_putstr_fd(env->up, env->fd_tty);
			while (count > env->col)
			{
				ft_putstr_fd(env->nd, env->fd_tty);
				count++;
			}
			count = 0;
		}
		else
			ft_putstr_fd(env->le, env->fd_tty);
		cpy_cc--;
		c++;
	}
}
