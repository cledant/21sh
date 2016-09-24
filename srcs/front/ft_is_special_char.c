/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_special_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 10:06:23 by cledant           #+#    #+#             */
/*   Updated: 2016/09/24 16:36:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_is_special_char(char s[4], t_env *env)
{
	int		key;

	ft_memcpy(&key, s, sizeof(int));
	if (key == ENTER && env->mode_copy == 0 && env->mline == 0)
		return (ft_enter(env));
	else if (key == CTRL_D && env->mode_copy == 0)
		return (ft_ctrl_d(env));
	else if (key == CLEAR_WIN)
		return (ft_ctrl_l(env));
	else if (key == HIST_UP && env->mode_copy == 0 && env->mline == 0)
		return (ft_hist_search(env, 0));
	else if (key == HIST_DOWN && env->mode_copy == 0 && env->mline == 0)
		return (ft_hist_search(env, 1));
	else if (key == CHAR_RIGHT)
		return (ft_cursor_right_buff(env));
	else if (key == CHAR_LEFT)
		return (ft_cursor_left_buff(env));
	else if (key == LINE_UP)
		return (ft_home(env));
	else if (key == LINE_DOWN)
		return (ft_end(env));
	else if (key == CUR_DEL && env->mode_copy == 0)
		return (ft_delete(env));
	else if (key == BACK_DEL && env->mode_copy == 0)
		return (ft_backdelete(env));
	else if (key == WORD_RIGHT)
		return (ft_word_right(env));
	else if (key == WORD_LEFT)
		return (ft_word_left(env));
	else if (key == BUFF_UP)
		return (ft_line_up(env));
	else if (key == BUFF_DOWN)
		return (ft_line_down(env));
	else if (key == SELECT_MODE  && env->mode_copy == 0)
		return (ft_start_copy(env));
	else if (key == COPY && env->mode_copy == 1)
		return (ft_set_copy(env, 0));
	else if (key == CUT && env->mode_copy == 1)
		return (ft_set_copy(env, 1));
	else if (key == ESC && env->mode_copy == 1)
		return (ft_reset_copy(env, 1));
	else if (key == PASTE && env->mode_copy == 0)
		return (ft_put_copy(env));
	else if (key == M_LINE)
		return (ft_mline(env));
	else if (key == ENTER && env->mline == 1) /*SKIP ENTER IN MULTI LINE*/
		return (0);
	else if (key == TAB) /*SKIP TAB*/
		return (0);
	else if ((ft_isprint(s[0]) == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0))
		return (1);
	else if ((ft_isprint(s[0]) < 0 || s[1] != 0 || s[2] != 0 || s[3] != 0))
		return (1);
	if (env->mode_copy == 1)
		return (1);
	return (0);
}
