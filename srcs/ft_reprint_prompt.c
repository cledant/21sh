/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reprint_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:46:02 by cledant           #+#    #+#             */
/*   Updated: 2016/07/15 10:53:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_reprint_prompt(char s[4], t_env *env)
{
	t_btree *cpy_cur_il;

	cpy_cur_il = env->cur_il;
	while(cpy_cur_il != NULL)
	{
		if (cpy_cur_il != NULL)
			ft_wputchar_char_fd(cpy_cur_il->content);
		cpy_cur_il = cpy_cur_il->right;
	}
}
