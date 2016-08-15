/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:58:45 by cledant           #+#    #+#             */
/*   Updated: 2016/08/15 20:00:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_line_down(t_env *env)
{
	size_t	bak;
	int		c;

	c = 0;
	if (env->cur_char + env->col > env->last_char)
		return (1);
	bak = env->cur_char;
	ft_cursor_move_to_end_prompt(env);
	env->cur_char = bak + env->col;
	ft_cursor_moveback_to_cur(env);
	if (env->cur_char - env->col == 2)
		c++;
	while (c < env->col)
	{
		env->cur_il = env->cur_il->right;
		c++;
	}
	return (1);
}
