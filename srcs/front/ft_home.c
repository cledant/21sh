/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:49:52 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:14:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_home(t_env *env)
{
	char	*s;

	if (env->cur_char == 2)
		return (1);
	if (env->cur_il->left != NULL)
		env->cur_il = env->cur_il->left;
	env->cur_char--;
	while (1)
	{
		s = env->cur_il->content;
		if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			break ;
		if (env->cur_char > 2)
			env->cur_char--;
		if (env->cur_il->left == NULL)
			break ;
		env->cur_il = env->cur_il->left;
	}
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
	ft_set_pos_col(env);
	return (1);
}
