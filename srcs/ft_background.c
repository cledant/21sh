/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 17:45:14 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 15:49:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_background(struct termios cpy_term, t_env **env)
{
	char	cmd[2];

	ft_putstr_fd((*env)->ve, (*env)->fd_tty);
	ft_putstr_fd((*env)->ho, (*env)->fd_tty);
	ft_putstr_fd((*env)->cl, (*env)->fd_tty);
	if (tcsetattr(0, TCSANOW, &cpy_term) == -1)
		ft_handler(20000);
	cmd[0] = 26;
	cmd[1] = '\0';
	signal(SIGTSTP, SIG_DFL);
	if (ioctl(0, TIOCSTI, cmd) == -1)
		ft_handler(20000);
	ft_putstr_fd((*env)->cl, (*env)->fd_tty);
}
