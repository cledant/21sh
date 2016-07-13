/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_special_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 10:06:23 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 14:28:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_is_special_char(char s[4], t_env *env)
{
	if ((s[0] == 10 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*enter*/
	{
		write(env->fd_tty, "\n", 1);
		ft_list_wputendl_fd(env->cur, env->fd_tty);
		if ((env->hist = ft_lstnewpushback_list(env->hist, env->cur)) == NULL)
			ft_handler(20000);
		write(env->fd_tty, "$>", 2);
		env->cur = NULL;
		return (1);
	}
	else if ((s[0] == 4 && s[1] == 0 && s[2] == 0 && s[3] == 0)) /*CTRL + D*/
		ft_handler(10000);
	return (0);
}
