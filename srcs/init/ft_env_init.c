/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:05:17 by cledant           #+#    #+#             */
/*   Updated: 2016/11/01 16:53:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline int		ft_env_init_btree(t_env *new)
{
	if ((new->first = ft_btree_new(NULL, 0)) == NULL)
		return (-1);
	if ((new->first->content = ft_btree_new(NULL, 0)) == NULL)
	{
		free(new->first);
		return (-1);
	}
	new->last = new->first;
	new->cur = new->first;
	new->cur_il = new->first->content;
	return (0);
}

static inline void		ft_env_init_next(t_env *new)
{
	new->cur_char = 0;
	new->first_char = 0;
	new->last_char = 0;
	new->mode_copy = 0;
	new->begin_copy = NULL;
	new->end_copy = NULL;
	new->begin_cur_char = 0;
	new->cpy = NULL;
	new->buff = NULL;
	new->buff_size = 2048;
	new->mline = 0;
	new->cur_buff = 0;
	new->last_buff = 0;
	new->inv_buff = NULL;
	new->pos_col = 0;
	new->pos_line = 0;
	new->cmd_line = NULL;
	new->env = NULL;
	new->err_quote = NULL;
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
	new->cd = NULL;
	new->up = NULL;
	new->le = NULL;
	new->sr = NULL;
	new->fd_tty = -1;
	new->col = 0;
	new->line = 0;
	new->first = NULL;
	new->last = NULL;
	new->cur = NULL;
	new->cur_il = NULL;
	ft_env_init_next(new);
}

t_env					*ft_env_init(void)
{
	t_env	*new;

	if ((new = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	ft_env_init_val(new);
	if ((new->buff = ft_memalloc(new->buff_size)) == NULL)
	{
		free(new);
		return (NULL);
	}
	if ((new->inv_buff = ft_memalloc(new->buff_size)) == NULL)
	{
		free(new);
		ft_memdel((void **)&(new->buff));
		return (NULL);
	}
	if ((new->stack_quote = ft_stack_new(STACK_INCREMENT)) == NULL)
	{
		ft_memdel((void **)&(new->buff));
		ft_memdel((void **)&(new->inv_buff));
		free(new);
		return (NULL);
	}
	if (ft_env_init_btree(new) == -1)
	{
		ft_memdel((void **)&(new->buff));
		ft_memdel((void **)&(new->inv_buff));
		ft_stack_delete(&(new->stack_quote));
		free(new);
		return (NULL);
	}
	return (new);
}
