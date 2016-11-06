/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:53:26 by cledant           #+#    #+#             */
/*   Updated: 2016/11/06 14:20:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_init(t_env *env, char (*s)[4])
{
	ft_bzero(*s, sizeof(char) * 4);
	env->first_char = 2;
	env->cur_char = 2;
	env->last_char = 2;
	env->last_buff = 2;
	env->cur_buff = 2;
}

static inline void		ft_if_copy(t_env *env)
{
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
	ft_putstr_fd(env->vi, env->fd_tty);
}

void					ft_read_input(t_env *env)
{
	char	s[4];

	ft_init(env, &s);
	(env->err_quote == NULL) ? write(env->fd_tty, "$>", 2) :
		write(env->fd_tty, "*>", 2);
	while (1)
	{
		if (read(0, s, sizeof(char) * 4) != 0)
		{
			if (ft_is_special_char(s, env) != 1)
			{
				if (env->mode_copy == 0)
					ft_insert_data(s, env);
				ft_print_buffer(env);
				ft_move_cursor_from_last_buff_to_cur_buff(env);
			}
			if (env->mode_copy == 1)
				ft_if_copy(env);
			ft_bzero(s, sizeof(char) * 4);
		}
	}
}
