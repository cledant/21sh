/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_cursor_from_cur_buff_to_end_buf          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 18:13:31 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:11:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_change_cursor_from_cur_buff_to_end_buff(t_env *env)
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
	env->cur_buff = counter;
	env->cur_char = env->last_char;
	while (env->cur_il->right != NULL)
		env->cur_il = env->cur_il->right;
	ft_putstr_fd(env->ve, env->fd_tty);
	return (1);
}
