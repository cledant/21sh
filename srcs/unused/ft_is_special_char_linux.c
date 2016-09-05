/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_special_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 10:06:23 by cledant           #+#    #+#             */
/*   Updated: 2016/08/24 17:27:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
/*
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
*/
int		ft_is_special_char(char s[4], t_env *env)
{
	if ((s[0] == 10 && s[1] == 0 && s[2] == 0 && s[3] == 0)
			&& env->mode_copy == 0 && env->too_small == 0) /*ENTER*/
		return (ft_enter(env));
	else if ((s[0] == 4 && s[1] == 0 && s[2] == 0 && s[3] == 0)
				&& env->mode_copy == 0) /*CTRL + D*/
		return (ft_ctrl_d(env));
	else if (s[0] == 12 && s[1] == 0 && s[2] == 0 && s[3] == 0) /*CTRL + L*/
		return (ft_ctrl_l(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 65 && s[3] == 0)
				&& env->mode_copy == 0) /*UP*/
		return (ft_hist_search(env, 0));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 66 && s[3] == 0)
				&& env->mode_copy == 0) /*DOWN*/
		return (ft_hist_search(env, 1));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 67 && s[3] == 0)) /*RIGHT*/
		return (ft_cursor_right_buff(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 68 && s[3] == 0)) /*LEFT*/
		return (ft_cursor_left_buff(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 72 && s[3] == 0)) /*HOME*/
		return (ft_home(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 70 && s[3] == 0)) /*END*/
		return (ft_end(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 51 && s[3] == 126)
				&& env->mode_copy == 0) /*DELETE*/
		return (ft_delete(env));
	else if ((s[0] == 127 && s[1] == 0 && s[2] == 0 && s[3] == 0)
				&& env->mode_copy == 0) /*BACK DEL*/
		return (ft_backdelete(env));
	else if ((s[0] == 27 && s[1] == 116 && s[2] == 0 && s[3] == 0)) /*ALT+T*/
		return (ft_word_right(env));
	else if ((s[0] == 27 && s[1] == 114 && s[2] == 0 && s[3] == 0)) /*ALT+R*/
		return (ft_word_left(env));
	else if ((s[0] == 27 && s[1] == 105 && s[2] == 0 && s[3] == 0)) /*ALT+I*/
		return (ft_line_up(env));
	else if ((s[0] == 27 && s[1] == 117 && s[2] == 0 && s[3] == 0)) /*ALT+U*/
		return (ft_line_down(env));
	else if ((s[0] == 27  && s[1] == 115 && s[2] == 0 && s[3] == 0) &&
				env->mode_copy == 0) /*ALT+S*/
		return (ft_start_copy(env));
	else if ((s[0] == 27  && s[1] == 99 && s[2] == 0 && s[3] == 0) &&
				env->mode_copy == 1) /*ALT+C*/
		return (ft_set_copy(env, 0));
	else if ((s[0] == 27  && s[1] == 120 && s[2] == 0 && s[3] == 0) &&
				env->mode_copy == 1) /*ALT+X*/
		return (ft_set_copy(env, 1));
	else if ((s[0] == 27  && s[1] == 0 && s[2] == 0 && s[3] == 0) &&
				env->mode_copy == 1) /*ESC copy*/
		return (ft_reset_copy(env, 1));
	else if ((s[0] == 27  && s[1] == 118 && s[2] == 0 && s[3] == 0) &&
				env->mode_copy == 0) /*ALT+V*/
		return (ft_put_copy(env));
//	else if ((s[0] == 5 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*DEBUG 1*/
//		return (ft_test_hist(env));
//	else if ((s[0] == 18 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*DEBUG 2*/
//		return (ft_test_hist_bis(env));
	else if ((s[0] == 27 && s[1] == 112 && s[2] == 0 && s[3] == 0)) /*DEBUG 
																		M-LINE*/
	{
		if (env->too_small == 0)
			env->too_small = 1;
		else
			env->too_small = 0;
		return (1);
	}
	else if (s[0] == 10 && s[1] == 0 && s[2] == 0 && s[3] == 0 &&
				env->too_small == 1) /*DEBUG MULTI LINE*/
		return (0);
	else if ((ft_isprint(s[0]) == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0))
		return (1);
	else if ((ft_isprint(s[0]) < 0 || s[1] != 0 || s[2] != 0 || s[3] != 0))
		return (1);
	if (env->mode_copy == 1)
		return (1);
	return (0);
}
