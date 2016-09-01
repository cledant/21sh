/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_cur_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 12:21:25 by cledant           #+#    #+#             */
/*   Updated: 2016/08/10 11:00:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_delete_cur_prompt(t_env *env)
{
	ft_putstr_fd(env->vi, env->fd_tty);
	while (env->cur_char > 0)
		ft_cursor_left_prompt(env);
	ft_putstr_fd(env->cd, env->fd_tty);
	ft_putstr_fd(env->ve, env->fd_tty);
}
