/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_special_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 10:06:23 by cledant           #+#    #+#             */
/*   Updated: 2016/08/16 22:40:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		ft_test_hist(t_env *env)
{
	t_btree		*test;

	test = env->first;
	ft_putendl_fd("", env->fd_tty);
	while (test != NULL)
	{
		ft_btree_wputendl_fd(test->content, env->fd_tty);
		test = test->right;
	}
	write(env->fd_tty, "$>", 2);
	return (1);
}

static int		ft_test_hist_bis(t_env *env)
{
	t_btree		*test;

	test = env->last;
	ft_putendl_fd("", env->fd_tty);
	while (test != NULL)
	{
		ft_btree_wputendl_fd(test->content, env->fd_tty);
		test = test->left;
	}
	write(env->fd_tty, "$>", 2);
	return (1);
}

int		ft_is_special_char(char s[4], t_env *env)
{
	if ((s[0] == 10 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*ENTER*/
	{
		write(env->fd_tty, "\n", 1);
		if (env->cur_il->content != NULL)
		{
			ft_btree_wputendl_fd(env->last->content, env->fd_tty);
			if ((env->last = ft_new_right_node(env)) == NULL)
			{
				ft_hist_destroy(&(env->first));
				ft_handler(20000);
			}
		}
		else
			env->cur = env->last;
		write(env->fd_tty, "$>", 2);
		return (1);
	}
	else if ((s[0] == 4 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*CTRL + D*/
	{
		if (env->cur_il->content == NULL)
		{
			ft_hist_destroy(&(env->first));
			ft_handler(10000);
		}
		return (1);
	}
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 65 && s[3] == 0)
				&& env->mode_copy == 0) /*UP*/
		return (ft_hist_search(env, 0));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 66 && s[3] == 0)
				&& env->mode_copy == 0) /*DOWN*/
		return (ft_hist_search(env, 1));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 67 && s[3] == 0)) /*RIGHT*/
		return (ft_cursor_right(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 68 && s[3] == 0)) /*LEFT*/
		return (ft_cursor_left(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 72 && s[3] == 0)) /*HOME*/
		return (ft_cursor_move_to_orig(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 70 && s[3] == 0)) /*END*/
		return (ft_cursor_move_to_end(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 51 && s[3] == 126)
				&& env->mode_copy == 0) /*DELETE*/
		return (ft_delete(env));
	else if ((s[0] == 127 && s[1] == 0 && s[2] == 0 && s[3] == 0)
				&& env->mode_copy == 0) /*BACK DEL*/
		return (ft_backdelete(env));
	else if ((s[0] == 27 && s[1] == 27 && s[2] == 91 && s[3] == 67)) /*OPT+RIGHT*/
		return (ft_word_right(env));
	else if ((s[0] == 27 && s[1] == 27 && s[2] == 91 && s[3] == 68)) /*OPT+LEFT*/
		return (ft_word_left(env));
	else if ((s[0] == 27 && s[1] == 27 && s[2] == 91 && s[3] == 65)) /*OPT+UP*/
		return (ft_line_up(env));
	else if ((s[0] == 27 && s[1] == 27 && s[2] == 91 && s[3] == 66)) /*OPT+DOWN*/
		return (ft_line_down(env));
	else if ((s[0] == -61  && s[1] == -89 && s[2] == 0 && s[3] == 0) &&
				env->mode_copy == 0) /*OPT+C start*/
		return (ft_start_copy(env));
	else if ((s[0] == -61  && s[1] == -89 && s[2] == 0 && s[3] == 0) &&
				env->mode_copy == 1) /*OPT+C set*/
		return (ft_set_copy(env));
	else if ((s[0] == 27  && s[1] == 0 && s[2] == 0 && s[3] == 0) &&
				env->mode_copy == 1) /*ESC copy*/
		return (ft_reset_copy(env));
	else if ((s[0] == -30  && s[1] == -120 && s[2] == -102 && s[3] == 0) &&
				env->mode_copy == 0) /*OPT+V*/
		return (ft_put_copy(env));
	else if ((s[0] == 5 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*DEBUG 1*/
		return (ft_test_hist(env));
	else if ((s[0] == 18 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*DEBUG 2*/
		return (ft_test_hist_bis(env));
	else if ((ft_isprint(s[0]) == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0))
		return (1);
	else if ((ft_isprint(s[0]) < 0 || s[1] != 0 || s[2] != 0 || s[3] != 0))
		return (1);
	return (0);
}
