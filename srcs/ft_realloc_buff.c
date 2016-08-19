/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 12:54:33 by cledant           #+#    #+#             */
/*   Updated: 2016/08/19 12:57:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_realloc_buff(t_env *env)
{
	ft_memdel(&(env->buff));
	env->buff_size += 2048;
	if ((env->buff = ft_memalloc(env->buff_size)) == NULL)
		ft_handler(20000);
}
