/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:58:45 by cledant           #+#    #+#             */
/*   Updated: 2016/09/11 17:08:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_line_down(t_env *env)
{
	t_btree		*cmd;
	char		*s;
	char		*s_next;
	size_t		c;
	size_t		type;

	if (env->cur_il->content == NULL)
		return (1);
	c = 0;
	type = 0;
	cmd = env->cur_il;
	while (1)
	{
		s = cmd->content;
		if (type == 0)
		{
			c++;
			if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			{
				type++;
				if (cmd->right != NULL)
				{
					s_next = cmd->right->content;
					if (s_next[0] == '\n' && s_next[1] == 0 && s_next[2] == 0
						&& s_next[3] == 0 && c == 1)
					{
						ft_cursor_right_buff_no_set(env);
						return (1);
					}
				}
				c = 0;
			}
		}
		else
		{
			if (c == env->pos_col)
				return (1);
			else if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			{
				ft_cursor_left_buff_no_set(env);
				return (1);
			}
			c++;
		}
		if (cmd->right != NULL)
		{
			ft_cursor_right_buff_no_set(env);
			cmd = cmd->right;
		}
		else
			return (1);
	}
	return (1);
}
