/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_cursor_from_cur_buff_to_prompt.          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 18:37:13 by cledant           #+#    #+#             */
/*   Updated: 2016/08/21 18:41:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_change_cursor_from_cur_buff_to_prompt(t_env *env)
{
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_putstr_fd(env->nd, env->fd_tty);
	ft_putstr_fd(env->nd, env->fd_tty);
	env->cur_char = 2;
	env->cur_buff = 2;
	env->cur_il = env->last->content;
	return (1);
}
