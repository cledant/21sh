/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pos_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 19:59:05 by cledant           #+#    #+#             */
/*   Updated: 2016/09/13 20:16:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void		ft_get_max_rl(t_env *env, t_btree *cmd)
{
	char	*s;

	while (cmd != NULL)
	{
		s = cmd->content;
		if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			env->max_rl++;
		cmd = cmd->right;
	}
}

void			ft_set_pos_col(t_env *env)
{
	t_btree		*cmd;
	char		*s;

	env->pos_col = 0;
	env->nb_rl = 0;
	env->max_rl = 0;
	cmd = env->last->content;
	if (cmd->content == NULL)
		return ;
	if (env->cur_char == 2)
	{
		ft_get_max_rl(env, cmd);
		return ;
	}
	env->pos_col++;
	while (cmd != env->cur_il)
	{
		s = cmd->content;
		if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
		{
			env->nb_rl++;
			env->max_rl++;
			env->pos_col = 0;
		}
		else
			env->pos_col++;
		cmd = cmd->right;
	}
	if (env->nb_rl == 0)
		env->pos_col--;
	ft_get_max_rl(env, cmd);
}
