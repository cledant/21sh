/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:32:26 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 15:50:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void			ft_prog_main(t_env *env)
{
	struct termios	term;
	char			*disp;

	disp = NULL;
	if (tcgetattr(0, &term) == -1)
		ft_handler(20000);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		ft_handler(20000);
	ft_putstr_fd(env->cl, env->fd_tty);
	ft_putstr_fd(env->vi, env->fd_tty);
/*	if ((disp = ft_selected_entry(env, 0)) != NULL)
	{
		ft_putstr_fd(env->cl, env->fd_tty);
		if (*disp != '\0')
			ft_putendl(disp);
		ft_strdel(&disp);
	}*/ //truc du ft_select a modif
	ft_putendl_fd("TEST", env->fd_tty);
	ft_handler(10000);
}
