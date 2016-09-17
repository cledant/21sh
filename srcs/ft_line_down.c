/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:53:35 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 13:54:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_line_down(t_env *env)
{
	size_t		target;

	if ((env->cur_buff / env->col) == (env->last_buff / env->col))
		return (1);
	target = ((env->cur_buff / env->col) + 1) * env->col + env->pos_col;
	while (env->cur_buff < target && env->cur_buff != env->last_buff)
		ft_cursor_right_buff_no_set(env);
	if (env->cur_buff > target)
		ft_cursor_left_buff_no_set(env);
	return (1);
}
