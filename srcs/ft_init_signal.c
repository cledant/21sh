/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:54:06 by cledant           #+#    #+#             */
/*   Updated: 2016/08/06 14:43:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_init_signal(void)
{
	signal(SIGINT, (void (*)(int))ft_handler);
	signal(SIGCONT, (void (*)(int))ft_handler);
	signal(SIGTSTP, (void (*)(int))ft_handler);
	signal(SIGABRT, (void (*)(int))ft_handler);
	signal(SIGALRM, (void (*)(int))ft_handler);
//	signal(SIGBUS, (void (*)(int))ft_handler);
	signal(SIGFPE, (void (*)(int))ft_handler);
	signal(SIGHUP, (void (*)(int))ft_handler);
	signal(SIGILL, (void (*)(int))ft_handler);
	signal(SIGPIPE, (void (*)(int))ft_handler);
	signal(SIGPROF, (void (*)(int))ft_handler);
	signal(SIGQUIT, (void (*)(int))ft_handler);
//	signal(SIGSEGV, (void (*)(int))ft_handler);
	signal(SIGSYS, (void (*)(int))ft_handler);
	signal(SIGTERM, (void (*)(int))ft_handler);
	signal(SIGTRAP, (void (*)(int))ft_handler);
	signal(SIGTTIN, (void (*)(int))ft_handler);
	signal(SIGTTOU, (void (*)(int))ft_handler);
	signal(SIGUSR1, (void (*)(int))ft_handler);
	signal(SIGUSR2, (void (*)(int))ft_handler);
	signal(SIGXCPU, (void (*)(int))ft_handler);
	signal(SIGXFSZ, (void (*)(int))ft_handler);
	signal(SIGVTALRM, (void (*)(int))ft_handler);
	signal(SIGEMT, (void (*)(int))ft_handler);
	signal(SIGWINCH, (void (*)(int))ft_handler);
}
