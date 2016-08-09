/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_cur_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 12:21:25 by cledant           #+#    #+#             */
/*   Updated: 2016/08/09 11:37:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_delete_cur_prompt(t_env *env)
{
	while (env->cur_char > 2)
		ft_cursor_left(env);
	ft_putstr_fd(env->le, env->fd_tty);
	ft_putstr_fd(env->le, env->fd_tty);
	ft_putstr_fd(env->cd, env->fd_tty);
}
