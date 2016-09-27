/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:54:27 by cledant           #+#    #+#             */
/*   Updated: 2016/09/27 20:12:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline t_btree		*ft_get_end(t_btree *begin, size_t *size)
{
	(*size)++;
	while (begin->right != NULL)
	{
		begin = begin->right;
		(*size)++;
	}
	return (begin);
}

static inline void			ft_case_else(t_env *env, t_btree *cpy_cpy,
								t_btree *end, size_t size)
{
	if (env->cur_il->right != NULL)
	{
		env->cur_il->right->left = end;
		end->right = env->cur_il->right;
	}
	env->cur_il->right = cpy_cpy;
	cpy_cpy->left = env->cur_il;
	env->cur_il = end;
	env->last_char += size;
	env->cur_char += size;
}

static inline void			ft_put_copy_case(t_env *env, t_btree *cpy_cpy,
								t_btree *end, size_t size)
{
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	if (env->cur_il->content == NULL)
	{
		free(env->last->content);
		env->last->content = cpy_cpy;
		env->cur_il = end;
		env->last_char += size;
		env->cur_char += size;
	}
	else if (env->cur_char == 2)
	{
		env->last->content = cpy_cpy;
		end->right = env->cur_il;
		env->cur_il->left = end;
		env->cur_il = end;
		env->last_char += size;
		env->cur_char += size;
	}
	else
		ft_case_else(env, cpy_cpy, end, size);
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
	ft_set_pos_col(env);
}

int							ft_put_copy(t_env *env)
{
	t_btree		*cpy_cpy;
	t_btree		*end;
	t_btree		*begin;
	size_t		size;

	if (env->cpy == NULL)
		return (1);
	size = 0;
	cpy_cpy = NULL;
	begin = env->cpy;
	while (begin != NULL)
	{
		if ((cpy_cpy = ft_btree_pushback_copy_pasta_node(begin, cpy_cpy, 0))
				== NULL)
			ft_handler(20000);
		begin = begin->right;
	}
	end = ft_get_end(cpy_cpy, &size);
	ft_put_copy_case(env, cpy_cpy, end, size);
	return (1);
}
