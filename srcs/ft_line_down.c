/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:58:45 by cledant           #+#    #+#             */
/*   Updated: 2016/09/11 19:20:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_line_down(t_env *env)
{
	t_btree		*cmd;
	char		*s;
	size_t		c;
	size_t		rl;

	if (env->cur_il->content == NULL || env->max_rl == env->nb_rl)
		return (1);
	c = 0;
	rl = 0;
	while (env->cur_il != env->last->content)
		ft_cursor_left_buff_no_set(env);
	cmd = env->last->content;
	while (rl < env->nb_rl + 1)
	{
		s = cmd->content;
		if (s[0] == '\n')
			rl++;
		if (cmd->right != NULL)
		{
			ft_cursor_right_buff_no_set(env);
			cmd = cmd->right;
		}
		else
			return (1);
	}
	while (1)
	{
		s = cmd->content;
		if (s[0] == '\n')
		{
			env->nb_rl++;
			ft_cursor_left_buff_no_set(env);
			return (1);
		}
		else if (c == env->pos_col)
		{
			env->nb_rl++;
			return (1);
		}
		c++;
		if (cmd->right != NULL)
		{
			ft_cursor_right_buff_no_set(env);
			cmd = cmd->right;
		}
		else
		{
			env->nb_rl++;
			return (1);
		}
	}
	return (1);
}
