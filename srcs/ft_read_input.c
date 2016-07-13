/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:53:26 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 09:54:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_read_input(t_env *env)
{
	char	s[4];
	t_list	*list;

	ft_bzero(s, sizeof(char) * 4);
	list = NULL;
	write(env->fd_tty, "$>", 2);
	while (1)
	{
		if (read(0, s, 4) != 0)
		{
			if ((s[0] == 10 && s[1] == 0 && s[2] == 0 && s[3] == 0))
			{
				write(env->fd_tty, "\n", 1);
				ft_list_wputendl_fd(list, env->fd_tty);
				ft_lstdel(&list, ft_lstfree_malloc);
				write(env->fd_tty, "$>", 2);
			}
			else
			{
				ft_wputchar_char_fd(s, env->fd_tty);
				if ((list = ft_lstnewpushback(list, s, 4)) == NULL)
					ft_handler(20000);
			}
			ft_bzero(s, sizeof(char) * 4);
		}
	}
}
