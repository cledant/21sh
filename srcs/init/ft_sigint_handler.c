/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigint_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 13:05:12 by cledant           #+#    #+#             */
/*   Updated: 2016/11/09 21:35:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_set_at_two(t_env *env)
{
	env->cur_char = 2;
	env->last_char = 2;
}

static inline void		ft_new_first(t_env *env)
{
	t_btree		*del;
	t_btree		*new;

	del = env->last;
	if ((new = ft_btree_new(NULL, 0)) == NULL)
		ft_handler(20000);
	if ((new->content = ft_btree_new(NULL, 0)) == NULL)
	{
		free(new);
		ft_handler(20000);
	}
	ft_hist_destroy(&del);
	env->first = new;
	env->cur = new;
	env->last = new;
	env->cur_il = new->content;
	if (env->err_quote != NULL)
	{
		free(new->content);
		new->content = env->err_quote;
		env->err_quote = NULL;
		if ((env->last = ft_new_right_node(env)) == NULL)
			ft_handler(20000);
	}
	ft_set_at_two(env);
}

static inline void		ft_recreate_node(t_env *env)
{
	t_btree		*del;

	del = env->last;
	if (env->last->left != NULL)
	{
		env->last = env->last->left;
		env->last->right = NULL;
		ft_hist_destroy(&del);
		if ((env->last = ft_new_right_node(env)) == NULL)
			ft_handler(20000);
		if (env->err_quote != NULL)
		{
			free(env->last->content);
			env->last->content = env->err_quote;
			env->err_quote = NULL;
			if ((env->last = ft_new_right_node(env)) == NULL)
				ft_handler(20000);
		}
	}
	else
		ft_new_first(env);
}

static inline size_t	ft_nb_line(t_env *env)
{
	size_t	nb_line;
	t_btree	*check;
	char	*s;

	if (env->last_buff % env->col == 0)
	{
		nb_line = env->last_buff / env->col + 2;
		if (env->last != NULL && env->last->content != NULL)
		{
			check = env->last->content;
			while (check->right != NULL)
				check = check->right;
			if (check->content != NULL)
			{
				s = check->content;
				if (s[0] == '\n')
					nb_line--;
			}
		}
	}
	else
		nb_line = env->last_buff / env->col + 1;
	return (nb_line);
}

void					ft_sigint_handler(t_env *env)
{
	size_t		nb_line;

	ft_reset_copy(env, 0);
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	nb_line = ft_nb_line(env);
	while (nb_line)
	{
		write(env->fd_tty, "\n", 1);
		nb_line--;
	}
	ft_recreate_node(env);
	ft_create_buffer(env);
	ft_putstr_fd(env->cd, env->fd_tty);
	ft_print_buffer(env);
}
