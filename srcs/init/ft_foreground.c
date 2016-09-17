/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 17:45:48 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 19:45:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_foreground(t_env *env)
{
	struct termios	term;

	signal(SIGTSTP, (void (*)(int))ft_handler);
	if (tcgetattr(0, &term) == -1)
		ft_handler(20000);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		ft_handler(20000);
	ft_change_termsize(env);
	ft_putstr_fd(env->cl, env->fd_tty);
	ft_putstr_fd(env->vi, env->fd_tty);
}
