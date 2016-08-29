/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_cut_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:28:33 by cledant           #+#    #+#             */
/*   Updated: 2016/08/26 03:11:33 by cledant          ###   ########.fr       */
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
	first = (sign == 0) ? env->begin_copy->left : env->end_copy->left;
	end = (sign == 0) ? env->end_copy->right : env->begin_copy->right;
	ptr = (sign == 0) ? env->begin_copy : env->end_copy;
	while (ptr != end)
	{
		del = ptr;
		ptr = ptr->right;
		ft_btree_delone(&del, ft_lstfree_malloc);
		c++;
	}
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_putstr_fd(env->cd, env->fd_tty);
	if (front == 1)
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
	else
	{
		env->last_char -= c;
		env->cur_char = (sign == 0) ? env->cur_char - c : env->cur_char;
		if (end != NULL)
			end->left = first;
		first->right = end;
		if (sign == 0)
		{
			env->cur_il = first;
			env->cur_char++;
		}
		else
			env->cur_il = first;
	}
	env->mode_copy = 0;
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
}
