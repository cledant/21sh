/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:13:52 by cledant           #+#    #+#             */
/*   Updated: 2016/08/17 11:29:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_start_copy(t_env *env)
{
	env->mode_copy = 1;
	env->begin_cur_char = env->cur_char;
	env->begin_copy = env->cur_il;
	return (1);
}
