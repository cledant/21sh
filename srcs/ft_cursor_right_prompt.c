/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_right_prompt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:08:44 by cledant           #+#    #+#             */
/*   Updated: 2016/08/15 14:08:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_cursor_right_prompt(t_env *env)
{
	if (env->cur_char % env->col == (unsigned int)(env->col - 1))
		write(env->fd_tty, "\n", 1);
	else
		ft_putstr_fd(env->nd, env->fd_tty);
	env->cur_char++;
}
