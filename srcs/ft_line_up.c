/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:09:10 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 15:36:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_line_up(t_env *env)
{
	size_t		target;
	size_t		nb_line;

	if ((env->cur_buff / env->col) == 0)
		return (1);
	nb_line = env->cur_buff / env->col;
	if (nb_line - 1 == 0)
		target = (nb_line - 1) * env->col + env->pos_col + 2;
	else
		target = (nb_line - 1) * env->col + env->pos_col;
	while (env->cur_buff > target && env->cur_buff != 0)
		ft_cursor_left_buff_no_set(env);
	return (1);
}
