/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 14:43:15 by cledant           #+#    #+#             */
/*   Updated: 2016/08/19 15:49:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_clear_line(t_env *env)
{
	ft_putstr_fd(env->vi, env->fd_tty);
	while (env->cur_clean > 0)
		ft_cursor_left_clean(env);
	ft_putstr_fd(env->cd, env->fd_tty);
	ft_putstr_fd(env->ve, env->fd_tty);
}
