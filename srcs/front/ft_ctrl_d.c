/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:21:11 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:12:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_ctrl_d(t_env *env)
{
	if (env->cur_il->content == NULL)
	{
		ft_hist_destroy(&(env->first));
		ft_handler(10000);
	}
	return (1);
}
