/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 14:27:32 by cledant           #+#    #+#             */
/*   Updated: 2016/08/07 19:38:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_print_data(char s[4], t_env *env)
{
	size_t	bak;
	
	if (env->cur_char == env->last_char)
		ft_wputchar_char_fd(s, env->fd_tty);
	else
	{
		bak = env->cur_char;
		ft_delete_cur_prompt(env);
		env->cur_char = bak;
		write(env->fd_tty, "$>", 2);
		ft_btree_wputstr_fd(env->last->content, env->fd_tty);
	}
}
