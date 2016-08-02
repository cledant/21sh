/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:49:22 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 13:23:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void		ft_init_handler(struct termios *cpy_term, t_env **env)
{
	struct winsize	size;

	if (tcgetattr(0, cpy_term) == -1 || ioctl(0, TIOCGWINSZ, &size) == -1)
	{
		ft_env_destroy(*env);
		ft_exit_mess(1);
	}
	(*env)->col = size.ws_col;
	(*env)->line = size.ws_row;
	ft_init_signal();
	ft_prog_main(*env);
}

static void		ft_quit(struct termios cpy_term, t_env **env, int mes)
{
	if (mes == 1)
		ft_putendl_fd("Error", 2);
	else if (mes == 2)
		ft_putendl_fd("Please use another terminal", 2);
	ft_putstr_fd((*env)->ve, (*env)->fd_tty);
	if ((*env)->fd_tty != -1)
		if (close((*env)->fd_tty) == -1)
			ft_putendl_fd("Error while closing fd", 2);
	ft_env_destroy(*env);
	if (tcsetattr(0, TCSANOW, &cpy_term) == -1)
	{
		ft_putendl_fd("Error while setting back terminal values", 2);
		exit(-2);
	}
	if (mes == 0)
		exit(0);
	exit(-1);
}

static void		ft_else(struct termios cpy_term, t_env **env,
					unsigned long int sig)
{
	if (sig == SIGINT || sig == SIGABRT || sig == 20000 ||
		sig == SIGALRM || sig == SIGBUS || sig == SIGFPE ||
		sig == SIGHUP || sig == SIGILL || sig == SIGPIPE ||
		sig == SIGPROF || sig == SIGQUIT || sig == SIGSEGV ||
		sig == SIGSYS || sig == SIGTERM || /*sig == SIGEMT ||*/
		sig == SIGTRAP || sig == SIGTTOU || sig == SIGUSR1 ||
		sig == SIGUSR2 || sig == SIGXCPU || sig == SIGXFSZ ||
		sig == SIGTTIN || sig == SIGVTALRM)
	{
		ft_putstr_fd((*env)->cl, (*env)->fd_tty);
		ft_quit(cpy_term, env, 1);
	}
	else if (sig == 20000)
		ft_quit(cpy_term, env, 1);
	else if (sig == 30000)
		ft_quit(cpy_term, env, 2);
//	else if (sig == SIGCONT)
//		ft_foreground(*env);
//	else if (sig == SIGTSTP)
//		ft_background(cpy_term, env);
	else if (sig == SIGWINCH)
		ft_change_termsize(*env);
}

void			ft_handler(unsigned long int sig)
{
	static struct termios		cpy_term;
	static t_env				*env = NULL;

	if (env == NULL)
	{
		env = (t_env *)sig;
		ft_init_handler(&cpy_term, &env);
	}
	else
	{
		if (sig == 10000)
			ft_quit(cpy_term, &env, 0);
		else
			ft_else(cpy_term, &env, sig);
	}
}
