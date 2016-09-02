/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:41:47 by cledant           #+#    #+#             */
/*   Updated: 2016/08/21 17:32:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_delete(t_env *env)
{
	if (env->cur_char == env->last_char && env->cur_char != 2)
		return (1);
	ft_btree_delete_node(env);
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_create_buffer(env);
	ft_putstr_fd(env->cd, env->fd_tty);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
	ft_set_pos_col(env);
	return (1);
}
