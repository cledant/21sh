/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:53:35 by cledant           #+#    #+#             */
/*   Updated: 2016/08/22 16:26:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_end(t_env *env)
{
	char	*s;

	if (env->cur_char == env->last_char)
		return (1);
	env->cur_char++;
	env->cur_il = env->cur_il->right;
	while (1)
	{
		s = env->cur_il->content;
		if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			break ;
		if (env->cur_il->right == NULL)
			break ;
		env->cur_il = env->cur_il->right;
		env->cur_char++;
	}
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
	return (1);
}
