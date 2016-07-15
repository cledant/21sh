/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_special_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 10:06:23 by cledant           #+#    #+#             */
/*   Updated: 2016/07/15 13:01:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_is_special_char(char s[4], t_env *env)
{
	if ((s[0] == 10 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*enter*/
	{
		write(env->fd_tty, "\n", 1);
		ft_btree_wputendl_fd(env->last, env->fd_tty);
		if ((env->last = ft_new_right_node(env)) == NULL)
			ft_handler(20000);
		write(env->fd_tty, "$>", 2);
		return (1);
	}
	else if ((s[0] == 4 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*CTRL + D*/
		ft_handler(10000);
//	else if ((s[0] == 27 && s[1] == 91 && s[2] == 65 && s[3] == 0)) /*UP*/
//		return (ft_hist_up(env));
//	else if ((s[0] == 27 && s[1] == 91 && s[2] == 66 && s[3] == 0)) /*DOWN*/
//		return (ft_hist_down(env));
//	else if ((s[0] == 27 && s[1] == 91 && s[2] == 67 && s[3] == 0)) /*RIGHT*/
//		return (ft_cursor_right(env));
//	else if ((s[0] == 27 && s[1] == 91 && s[2] == 68 && s[3] == 0)) /*LEFT*/
//		return (ft_cursor_left(env));
	else if ((s[0] == 27 && s[1] == 91 && s[2] == 51 && s[3] == 126)) /*DELETE*/
		return (ft_delete(env));
	else if ((s[0] == 127 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*BACK DEL*/
		return (ft_backdelete(env));
	return (0);
}
