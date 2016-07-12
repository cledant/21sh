/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:14:34 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 15:12:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_env_destroy(t_env *env)
{
	if (env->term_cap != NULL)
		ft_strdel(&(env->term_cap));
	ft_memdel((void **)&env);
}
