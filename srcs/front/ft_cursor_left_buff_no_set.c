/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left_buff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 19:14:24 by cledant           #+#    #+#             */
/*   Updated: 2016/09/24 15:47:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_cursor_left_buff_no_set(t_env *env)
{
	t_btree		*line;
	t_btree		*target;
	size_t		c;
	char		*s;
	size_t		counter;

	if (env->cur_char == 2)
		return (1);
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	target = env->cur_il;
	if (env->cur_il->left != NULL)
		env->cur_il = env->cur_il->left;
	line = env->last->content;
	env->cur_char--;
	c = 2;
	counter = 0;
	ft_putstr_fd(env->vi, env->fd_tty);
	ft_putstr_fd(env->nd, env->fd_tty);
	ft_putstr_fd(env->nd, env->fd_tty);
	while (line != target)
	{
		s = line->content;
		if (s[0] == '\n')
		{
			while (c % env->col != (unsigned int)(env->col - 1))
			{
				ft_putstr_fd(env->nd, env->fd_tty);
				c++;
			}
			ft_putchar_fd('\n', env->fd_tty);
			c++;
		}
		else if (s[0] == '\t')
		{
			while (counter < TAB_LEN)
			{
				if (c % env->col == (unsigned int)(env->col - 1))
					ft_putchar_fd('\n', env->fd_tty);
				else
					ft_putstr_fd(env->nd, env->fd_tty);
				c++;
				counter++;
			}
			counter = 0;
		}
		else
		{
			if (c % env->col == (unsigned int)(env->col - 1))
				ft_putchar_fd('\n', env->fd_tty);
			else
				ft_putstr_fd(env->nd, env->fd_tty);
			c++;
		}
		line = line->right;
	}
	env->cur_buff = c;
	env->pos_line = env->cur_buff / env->col;
	ft_putstr_fd(env->ve, env->fd_tty);
	return (1);
}
