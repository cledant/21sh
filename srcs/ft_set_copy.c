/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:19:50 by cledant           #+#    #+#             */
/*   Updated: 2016/08/16 11:50:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_set_copy(t_env *env)
{
	int		len;

	ft_putstr_fd(env->me, env->fd_tty);
	if ((len = env->begin_cur_char - env->cur_char) == 0)
		return (1);
	if (env->cpy != NULL)
	{
		ft_btree_clear_content(&env->cpy);
		env->cpy = NULL;
	}
	if ((env->cpy = ft_btree_set_copy_paste(env->begin_copy, len)) == NULL)
		ft_handler(20000);
	return (1);
}
