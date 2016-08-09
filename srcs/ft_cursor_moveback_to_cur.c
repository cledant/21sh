/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_moveback_to_cur.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:11:53 by cledant           #+#    #+#             */
/*   Updated: 2016/08/09 17:57:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_cursor_moveback_to_cur(t_env *env)
{
//	int		count;
	size_t	cpy_cc;

//	count = 0;
	cpy_cc = env->last_char;
	while (cpy_cc > env->cur_char)
	{
		if (cpy_cc % env->col == 0)
		{
			ft_putstr_fd(env->up, env->fd_tty);
//			while (count > env->col)
//			{
//				ft_putstr_fd(env->nd, env->fd_tty);
//				count++;
//			}
//			count = 0;
		}
//		else if (cpy_cc % env->col == env->col - 1)
//			write(env->fd_tty, "\n", 1);
		else
			ft_putstr_fd(env->le, env->fd_tty);
		cpy_cc--;
	}
}
