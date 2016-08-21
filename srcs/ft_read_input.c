/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:53:26 by cledant           #+#    #+#             */
/*   Updated: 2016/08/21 13:50:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_read_input(t_env *env)
{
	char	s[4];

	ft_bzero(s, sizeof(char) * 4);
	env->first_char = 2;
	env->cur_char = 2;
	env->last_char = 2;
	env->last_buff = 2;
	env->cur_buff = 2;
	write(env->fd_tty, "$>", 2);
	while (1)
	{
		if (read(0, s, 4) != 0)
		{
			env->cur_clean = env->cur_buff;
			if (ft_is_special_char(s, env) != 1)
			{
				if (env->mode_copy == 0)
					ft_insert_data(s, env);
				ft_print_buffer(env);
				ft_move_cursor_from_last_buff_to_cur_buff(env);
			}
			ft_bzero(s, sizeof(char) * 4);
		}
	}
}
