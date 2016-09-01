/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_move_to_end_prompt.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:08:25 by cledant           #+#    #+#             */
/*   Updated: 2016/08/15 14:08:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_cursor_move_to_end_prompt(t_env *env)
{
	while (env->last_char != env->cur_char)
		ft_cursor_right_prompt(env);
	return (1);
}
