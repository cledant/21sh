/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:08:48 by cledant           #+#    #+#             */
/*   Updated: 2016/08/19 16:46:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_print_buffer(t_env *env)
{
	size_t 		c;
	char		rl;
	char		space;

	c = 0;
	space = ' ';
	rl = '\n';
	ft_putstr_fd(env->vi, env->fd_tty);
	while (c < env->last_buff)
	{
		if ((env->buff)[c] == 0)
			write(env->fd_tty, &space, 1);
		else
			write(env->fd_tty, &(env->buff[c]), 1);
		if (c % env->col == (unsigned int)(env->col - 1))
			write(env->fd_tty, &rl, 1);
		c++;
	}
	ft_putstr_fd(env->ve, env->fd_tty);
}
