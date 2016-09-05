/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pos_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 19:59:05 by cledant           #+#    #+#             */
/*   Updated: 2016/09/05 19:59:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_set_pos_col(t_env *env)
{
	t_btree		*cmd;
	char		*s;

	env->pos_col = 0;
	cmd = env->last->content;
	if (cmd->content == NULL)
		return ;
	while (cmd != env->cur_il)
	{
		s = cmd->content;
		if (s[0] == '\n' && s[1] == 0 && s[2] == 0 && s[3] == 0)
			env->pos_col = 0;
		else
			env->pos_col++;	
		cmd = cmd->right;
	}
}
