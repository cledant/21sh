/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:53:35 by cledant           #+#    #+#             */
/*   Updated: 2016/09/25 21:00:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_display(t_env *env)
{
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
	ft_set_pos_col(env);
}

static inline void		ft_while(t_env *env, char *s)
{
	t_btree	*next;

	while (1)
	{
		if (env->cur_il->right == NULL)
		{
			if (env->cur_char < env->last_char)
				env->cur_char++;
			break ;
		}
		next = env->cur_il->right;
		s = next->content;
		if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			break ;
		if (env->cur_il->right == NULL)
			break ;
		if (env->cur_char < env->last_char)
			env->cur_char++;
		env->cur_il = env->cur_il->right;
	}
}

int						ft_end(t_env *env)
{
	char	*s;

	if (env->cur_il->content == NULL || (env->cur_char != 2
		&& env->cur_il->right == NULL))
		return (1);
	if (env->cur_char != 2)
		env->cur_il = env->cur_il->right;
	env->cur_char++;
	s = env->cur_il->content;
	if (env->cur_il == env->last->content && (s[0] == '\n' && s[1] == 0
		&& s[2] == 0 && s[3] == 0))
	{
		ft_display(env);
		return (1);
	}
	ft_while(env, s);
	ft_display(env);
	return (1);
}
