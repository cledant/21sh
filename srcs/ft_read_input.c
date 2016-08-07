/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:53:26 by cledant           #+#    #+#             */
/*   Updated: 2016/08/07 18:34:10 by cledant          ###   ########.fr       */
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
	write(env->fd_tty, "$>", 2);
	while (1)
	{
		if (read(0, s, 4) != 0)
		{
			if (ft_is_special_char(s, env) != 1)
			{
				ft_insert_char(s, env);
				ft_print_data(s, env);
			}
			ft_bzero(s, sizeof(char) * 4);
		}
	}
}
