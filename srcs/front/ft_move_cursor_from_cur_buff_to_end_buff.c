/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor_to_end_buff.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 12:37:27 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:21:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_move_cursor_from_cur_buff_to_end_buff(t_env *env)
{
	size_t	counter;

	counter = env->cur_buff;
	ft_putstr_fd(env->vi, env->fd_tty);
	while (counter < env->last_buff)
	{
		if (counter % env->col == (unsigned int)(env->col - 1))
			write(env->fd_tty, "\n", 1);
		else
			ft_putstr_fd(env->nd, env->fd_tty);
		counter++;
	}
	ft_putstr_fd(env->ve, env->fd_tty);
}
