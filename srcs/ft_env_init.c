/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:05:17 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 10:25:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static inline void		ft_env_init_val(t_env *new)
{
	new->term_cap = NULL;
	new->cl = NULL;
	new->vi = NULL;
	new->ve = NULL;
	new->us = NULL;
	new->ue = NULL;
	new->ho = NULL;
	new->ce = NULL;
	new->mr = NULL;
	new->me = NULL;
	new->nd = NULL;
	new->doo = NULL;
	new->cr = NULL;
	new->fd_tty = -1;
	new->col = 0;
	new->line = 0;
	new->hist = NULL;
	new->cur = NULL;
}

t_env					*ft_env_init(void)
{
	t_env	*new;

	if ((new = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	ft_env_init_val(new);
	return (new);
}
