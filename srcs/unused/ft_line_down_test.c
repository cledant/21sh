/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:58:45 by cledant           #+#    #+#             */
/*   Updated: 2016/09/06 20:26:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_line_down(t_env *env)
{
	t_btree		*cmd;
	char		*s;
	size_t		c;
	size_t		gc;
	size_t		type;
	size_t		flag;

	if (env->cur_il->content == NULL)
		return (1);
	c = 0;
	gc = 0;
	type = 0;
	flag = 0;
	cmd = env->cur_il;
	while (1)
	{
		s = cmd->content;
		if (type == 0)
		{
			if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			{
				type++;
				flag++;
			}
		}
		else if (type == 1)
		{
			if ((s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0) ||
					env->pos_col == 0)
			{
				type++;
//				if (flag == 0)
					cmd = cmd->left;
				if (env->pos_col != 0)
					gc--;
				break ;
			}
			else if (c == env->pos_col)
			{
				type++;
				break ;
			}
			c++;
			if (flag == 1)
				flag = 0;
		}
		if (cmd->right != NULL)
		{
			cmd = cmd->right;
			gc++;
		}
		else
			break ;
	}
	if (type == 1 || type == 2)
	{
		env->cur_il = cmd;
		env->cur_char += gc;
		ft_move_cursor_from_cur_buff_to_before_prompt(env);
		ft_create_buffer(env);
		ft_print_buffer(env);
		ft_move_cursor_from_last_buff_to_cur_buff(env);
	}
	return (1);
}
