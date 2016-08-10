/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_cur_prompt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 10:44:41 by cledant           #+#    #+#             */
/*   Updated: 2016/08/10 10:44:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_move_to_cur_prompt(t_env *env)
{
	while (env->cur_char > 0)
		ft_cursor_left_prompt(env);
}
