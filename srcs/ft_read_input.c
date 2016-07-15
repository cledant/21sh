/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:53:26 by cledant           #+#    #+#             */
/*   Updated: 2016/07/15 10:59:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_read_input(t_env *env)
{
	char	s[4];

	ft_bzero(s, sizeof(char) * 4);
	write(env->fd_tty, "$>", 2);
	env->cur_char = 2;
	while (1)
	{
		if (read(0, s, 4) != 0)
		{
			if (ft_is_special_char(s, env) != 1)
			{
				if (cur_il->content != NULL)
					ft_reprint_prompt(s, env);
				else
					ft_wputchar_char_fd(s, env->fd_tty);
				if ((env->cur_il = ft_btree_insert_node(env->cur_il, s, 4))
						== NULL)
					ft_handler(20000);
				env->cur_char++;
				env->cur = env->last;
			}
			ft_bzero(s, sizeof(char) * 4);
		}
	}
}
