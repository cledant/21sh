/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:05:17 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 19:00:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static inline int		ft_env_init_btree(t_env *new)
{
	if ((new->first = ft_btree_new(NULL, 0)) == NULL)
		return (-1);
	if ((new->first->content = ft_btree_new(NULL, 0)) == NULL)
	{
		free(new->first);
		return (-1)
	}
	new->last = new->first;
	new->cur = new->first;
	new->cur_il = new->first->content;
	return (0);
}

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
	new->first = NULL;
	new->last = NULL;
	new->cur = NULL;
	new->cur_il = NULL;
	new->cur_char = 0;
}

t_env					*ft_env_init(void)
{
	t_env	*new;

	if ((new = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	ft_env_init_val(new);
	if (ft_env_init_btree(new) == -1)
	{
		free(new);
		return (NULL);
	}
	return (new);
}
