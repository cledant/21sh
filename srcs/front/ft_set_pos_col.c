/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pos_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 19:59:05 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:24:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			ft_set_pos_col(t_env *env)
{
	if (env->cur_buff < (size_t)env->col)
		env->pos_col = env->cur_buff % env->col - 2;
	else
		env->pos_col = env->cur_buff % env->col;
	env->pos_line = env->cur_buff / env->col;
}
