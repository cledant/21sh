/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:53:35 by cledant           #+#    #+#             */
/*   Updated: 2016/08/23 15:11:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_end(t_env *env)
{
	char	*s;
	t_btree	*next;

	if (env->cur_il->right == NULL)
		return (1);
	env->cur_il = env->cur_il->right;
	env->cur_char++;
	while (1)
	{
		if (env->cur_il->right == NULL)
		{
			env->cur_char++;
			break ;
		}
		next = env->cur_il->right;
		s = next->content;
		if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			break ;
		if (env->cur_il->right == NULL)
			break ;
		env->cur_char++;
		env->cur_il = env->cur_il->right;
	}
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
	return (1);
}
