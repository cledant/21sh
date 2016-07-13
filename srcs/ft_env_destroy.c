/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:14:34 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 11:17:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_env_destroy(t_env *env)
{
	if (env->term_cap != NULL)
		ft_strdel(&(env->term_cap));
	if (env->hist != NULL)
		ft_hist_destroy(&(env->hist));
	if (env->cur != NULL)
		ft_lstdel(&(env->cur), &ft_lstfree_malloc);
	ft_memdel((void **)&env);
}
