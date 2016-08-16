/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:13:52 by cledant           #+#    #+#             */
/*   Updated: 2016/08/16 12:30:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_start_copy(t_env *env)
{
	env->mode_copy = 1;
	env->begin_cur_char = env->cur_char;
	env->begin_copy = env->cur_il;
	ft_putstr_fd(env->mr, env->fd_tty);
	return (1);
}
