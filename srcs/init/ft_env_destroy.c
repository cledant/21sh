/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:14:34 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 19:44:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_env_destroy(t_env *env)
{
	if (env->term_cap != NULL)
		ft_strdel(&(env->term_cap));
	if (env->first != NULL)
		ft_hist_destroy(&(env->last));
	if (env->cpy != NULL)
		ft_btree_clear_content(&env->cpy);
	if (env->buff != NULL)
		ft_memdel((void **)&(env->buff));
	if (env->inv_buff != NULL)
		ft_memdel((void **)&(env->inv_buff));
	ft_memdel((void **)&env);
}
