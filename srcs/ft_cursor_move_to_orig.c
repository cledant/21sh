/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_move_to_orig.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:17:30 by cledant           #+#    #+#             */
/*   Updated: 2016/08/09 11:27:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_cursor_move_to_orig(t_env *env)
{
	while (env->cur_char > 2)
		ft_cursor_left(env);
	return (1);
}
