/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 00:11:59 by cledant           #+#    #+#             */
/*   Updated: 2016/08/15 14:15:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_line_up(t_env *env)
{
	size_t	line;
	size_t	col;
	int		c;
	size_t	bak;

	c = 0;
	if ((line = env->cur_char / env->col) == 0)
		return (1);
	col = env->cur_char % env->col;
	if (line == 1 && (col == 0 || col == 1))
		return (1);
	bak = env->cur_char;
	ft_cursor_move_to_end_prompt(env);
	env->cur_char = bak - env->col;
	ft_cursor_moveback_to_cur(env);
	while (c < env->col)
	{
		if (env->cur_il->left != NULL)
			env->cur_il = env->cur_il->left;
		c++;
	}
	return (1);
}
