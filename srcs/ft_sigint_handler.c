/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigint_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 13:05:12 by cledant           #+#    #+#             */
/*   Updated: 2016/08/16 22:28:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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
	env->cur_char = 2;
	env->last_char = 2;
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
	}
	else
		ft_new_first(env);
}

void	ft_sigint_handler(t_env *env)
{
	size_t		nb_line;

	ft_reset_copy(env);
	while (env->cur_char > 0)
		ft_cursor_left_prompt(env);
	if (env->last_char % env->col == 0)
		nb_line = env->last_char / env->col + 2;
	else
		nb_line = env->last_char / env->col + 1;
	while (nb_line)
	{
		write(env->fd_tty, "\n", 1);
		nb_line--;
	}
	write(env->fd_tty, "$>", 2);
	ft_recreate_node(env);
}
