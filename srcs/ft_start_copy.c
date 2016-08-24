/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:13:52 by cledant           #+#    #+#             */
/*   Updated: 2016/08/24 15:43:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_start_copy(t_env *env)
{
	if (env->cur_il->content == NULL)
		return (1);
	env->mode_copy = 1;
	env->begin_cur_char = env->cur_char;
	if (env->cur_char == 2 || env->cur_char == env->last_char)
		env->begin_copy = env->cur_il;
	else
		env->begin_copy = env->cur_il->right;
	return (1);
}
