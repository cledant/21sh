/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left_buff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 19:14:24 by cledant           #+#    #+#             */
/*   Updated: 2016/09/27 19:27:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

inline void		ft_cursor_case_one(t_env *env, size_t *c)
{
	while (*c % env->col != (unsigned int)(env->col - 1))
	{
		ft_putstr_fd(env->nd, env->fd_tty);
		(*c)++;
	}
	ft_putchar_fd('\n', env->fd_tty);
	(*c)++;
}

inline void		ft_cursor_case_two(t_env *env, size_t *c)
{
	size_t	counter;

	counter = 0;
	while (counter < TAB_LEN)
	{
		if (*c % env->col == (unsigned int)(env->col - 1))
			ft_putchar_fd('\n', env->fd_tty);
		else
			ft_putstr_fd(env->nd, env->fd_tty);
		(*c)++;
		counter++;
	}
}

inline void		ft_cursor_case_three(t_env *env, size_t *c)
{
	if (*c % env->col == (unsigned int)(env->col - 1))
		ft_putchar_fd('\n', env->fd_tty);
	else
		ft_putstr_fd(env->nd, env->fd_tty);
	(*c)++;
}
