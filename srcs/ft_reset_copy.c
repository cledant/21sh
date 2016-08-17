/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:17:44 by cledant           #+#    #+#             */
/*   Updated: 2016/08/17 13:21:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_reset_copy(t_env *env, size_t disp)
{
	env->mode_copy = 0;
	env->begin_cur_char = 0;
	env->begin_copy = NULL;
	ft_putstr_fd(env->me, env->fd_tty);
	if (disp == 1)
		ft_print_line(env);
	return (1);
}
