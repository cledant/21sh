/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:53:26 by cledant           #+#    #+#             */
/*   Updated: 2016/07/15 14:57:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_read_input(t_env *env)
{
	char	s[4];

	ft_bzero(s, sizeof(char) * 4);
	write(env->fd_tty, "$>", 2);
	while (1)
	{
		if (read(0, s, 4) != 0)
		{
			if (ft_is_special_char(s, env) != 1)
			{
				ft_print_data(s, env);
				if ((env->cur_il = ft_btree_insert_node(env->cur_il, s, 4))
						== NULL)
					ft_handler(20000);
				env->cur_char++;
				env->last_char++;
				env->cur = env->last;
			}
			ft_bzero(s, sizeof(char) * 4);
		}
	}
}
