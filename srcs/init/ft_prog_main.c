/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:32:26 by cledant           #+#    #+#             */
/*   Updated: 2016/09/19 20:57:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			ft_prog_main(t_env *env)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		ft_handler(20000);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		ft_handler(20000);
	ft_putstr_fd(env->cl, env->fd_tty);
	ft_read_input(env);
	ft_handler(10000);
}
