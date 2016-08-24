/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_cut_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:28:33 by cledant           #+#    #+#             */
/*   Updated: 2016/08/24 21:16:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_btree_cut_nodes(t_env *env, int len)
{
	size_t		sign;
	size_t		front;
	size_t		c;
	t_btree		*first;
	t_btree		*end;
	t_btree		*ptr;
	t_btree		*del;

	sign = (len < 0) ? 0 : 1;
	first = NULL;
	c = 0;
	front = (env->begin_copy == env->last->content || env->end_copy ==
		env->last->content) ? 1 : 0;
	if (front == 1)
		first = (sign == 0) ? env->begin_copy->left : env->begin_copy->right;
	end = (sign == 0) ? env->end_copy->right : env->end_copy->left;
	ptr = env->begin_copy;
	while (ptr != end)
	{
		del = ptr;
		ptr = (sign == 0) ? ptr->right : ptr->left;
		ft_btree_delone(&del, ft_lstfree_malloc);
		c++;
	}
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	if (front == 1)
	{
		env->last->content = end;
		env->cur_char -= c;
		env->last_char -= c;
		if (end == NULL)
		{
			env->last->content = ft_btree_new(NULL, 0);
			env->cur_il = env->last->content;
			env->cur_char = 2;
			env->last_char = 2;
		}
	}
	else
	{
		env->cur_char -= c;
		env->last_char -= c;
		if (sign == 0)
		{
			env->begin_copy->right = end;
			env->end_copy->left = first;
		}
		else
		{
			env->begin_copy->left = end;
			env->end_copy->right = first;		
		}
		env->cur_il = end;
	}
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
}
