/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_right_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 11:49:00 by cledant           #+#    #+#             */
/*   Updated: 2016/09/24 15:49:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_cursor_right_buff_no_set(t_env *env)
{
	t_btree		*line;
	t_btree		*target;
	size_t		c;
	char		*s;
	size_t		flag;
	size_t		counter;

	if (env->cur_char == env->last_char)
			return (1);
	if ((env->cur_char == env->last_char - 1) && env->mode_copy == 1)
			return (1);
	flag = 0;
	counter = 0;
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	if (env->cur_char != 2)
		env->cur_il = env->cur_il->right;
	if (env->cur_il->right == NULL)
	{
		flag = 1;
		target = env->cur_il;
	}
	else
		target = env->cur_il->right;
	line = env->last->content;
	env->cur_char++;
	c = 2;
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
	if (flag == 1)
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
