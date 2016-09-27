/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_cut_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:28:33 by cledant           #+#    #+#             */
/*   Updated: 2016/09/27 18:42:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_case_one(t_env *env, t_btree *first, t_btree *end,
							size_t c)
{
	if (first == NULL && end == NULL)
	{
		if ((env->last->content = ft_btree_new(NULL, 0)) == NULL)
			ft_handler(20000);
		env->cur_il = env->last->content;
		env->cur_char = 2;
		env->last_char = 2;
	}
	else
	{
		env->last->content = end;
		env->last_char -= c;
		env->cur_il = end;
		env->cur_il->left = NULL;
		env->cur_char = 2;
		if (end == NULL)
		{
			if ((env->last->content = ft_btree_new(NULL, 0)) == NULL)
				ft_handler(20000);
			env->cur_il = env->last->content;
			env->cur_char = 2;
			env->last_char = 2;
		}
	}
}

static inline void		ft_case_two(t_env *env, t_btree *first, t_btree *end,
							size_t c[3])
{
	env->last_char -= c[0];
	env->cur_char = (c[1] == 0) ? env->cur_char - c[0] : env->cur_char;
	if (end != NULL)
		end->left = first;
	first->right = end;
	if (c[1] == 0)
	{
		env->cur_il = first;
		if (env->cur_char < env->last_char)
			env->cur_char++;
	}
	else
		env->cur_il = first;
}

static inline void		ft_cut_node_end(t_env *env, t_btree *first,
							t_btree *end, size_t c[3])
{
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_putstr_fd(env->cd, env->fd_tty);
	if (c[2] == 1)
		ft_case_one(env, first, end, c[0]);
	else
		ft_case_two(env, first, end, c);
	env->mode_copy = 0;
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
}

void					ft_btree_cut_nodes(t_env *env, int len)
{
	size_t		c[3];
	t_btree		*first;
	t_btree		*end;
	t_btree		*ptr;
	t_btree		*del;

	c[0] = 0;
	c[1] = (len < 0) ? 0 : 1;
	c[2] = (env->begin_copy == env->last->content || env->end_copy ==
		env->last->content) ? 1 : 0;
	first = (c[1] == 0) ? env->begin_copy->left : env->end_copy->left;
	end = (c[1] == 0) ? env->end_copy->right : env->begin_copy->right;
	ptr = (c[1] == 0) ? env->begin_copy : env->end_copy;
	while (ptr != end)
	{
		del = ptr;
		ptr = ptr->right;
		ft_btree_delone(&del, ft_lstfree_malloc);
		c[0]++;
	}
	ft_cut_node_end(env, first, end, c);
}
