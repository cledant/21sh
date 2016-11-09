/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter_content_not_null.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:48:13 by cledant           #+#    #+#             */
/*   Updated: 2016/11/09 22:03:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline size_t	ft_btree_length(t_btree *tree)
{
	size_t	len;

	len = 0;
	while (tree != NULL)
	{
		tree = tree->right;
		len++;
	}
	return (len);
}

static inline void		ft_add_return_line(t_env *env)
{
	t_btree		*ret_line;
	t_btree		*cpy_last;
	char		enter[4];

	ft_bzero(&enter, 4);
	enter[0] = '\n';
	cpy_last = env->last->content;
	if ((ret_line = ft_btree_new(enter, 4)) == NULL)
		ft_handler(20000);
	while (cpy_last->right != NULL)
		cpy_last = cpy_last->right;
	cpy_last->right = ret_line;
	ret_line->left = cpy_last;
}

static inline void		ft_convert_list_into_str(t_env *env)
{
	if (env->cmd_line != NULL)
		ft_strdel(&(env->cmd_line));
	if ((env->cmd_line = ft_convert_btree_to_str(env->last->content,
			ft_btree_length(env->last->content))) == NULL)
		ft_handler(20000);
}

static inline void		ft_else(t_env *env, int type)
{
	ft_add_return_line(env);
	if (ft_new_right_node_error_quote(env, type) != 1)
		ft_handler(20000);
}

void					ft_enter_content_not_null(t_env *env)
{
	if (env->err_quote != NULL)
	{
		ft_add_to_err_quote(env);
		if (ft_check_quotes(env->stack_quote, env->err_quote) == 1)
		{
			ft_clear_err_quote(env);
			ft_convert_list_into_str(env);
			if ((env->last = ft_new_right_node(env)) == NULL)
				ft_handler(20000);
		}
		else
			ft_else(env, 0);
	}
	else
	{
		if (ft_check_quotes(env->stack_quote, env->last->content) == 1)
		{
			ft_convert_list_into_str(env);
			if ((env->last = ft_new_right_node(env)) == NULL)
				ft_handler(20000);
		}
		else
			ft_else(env, 1);
	}
}
