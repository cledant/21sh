/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_insert_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:42:37 by cledant           #+#    #+#             */
/*   Updated: 2016/08/20 12:13:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_insert_data(char s[4], t_env *env)
{
	ft_insert_char(s, env);
	ft_create_buffer(env);
	ft_putstr_fd(env->vi, env->fd_tty);
	while (env->cur_clean > 0)
		ft_cursor_left_clean(env);
	ft_putstr_fd(env->ve, env->fd_tty);
}
