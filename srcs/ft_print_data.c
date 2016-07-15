/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 14:27:32 by cledant           #+#    #+#             */
/*   Updated: 2016/07/15 15:50:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	ft_over_cap(char s[4], t_env *env)
{
	size_t	disp;

	ft_putendl_fd(env->cl);
	if (env->line * env->col >= 9)
	{
		write(env->fd_tty, "$>", 2);
		disp = 2;
		if (env->first != 0)
		{
			write(env->fd, ">", 1);
			disp++;
		}
		
	}
	else
		env->block = 1;
}

void		ft_print_data(char s[4], t_env *env)
{
	long int	cap;
	size_t		len;

	cap = env->line * env->col;
	len = ft_btree_length(env->last);
	if (len + 2 > cap)
		ft_over_cap(s, env);
	else
	{
		if (env->cur_il->content != NULL)
			ft_reprint_prompt(s, env);
		else
			ft_wputchar_char_fd(s, env->fd_tty);
	}
}
