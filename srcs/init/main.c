/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 14:18:30 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 20:46:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		main_part2(t_env *env)
{
	if ((env->term_cap = ft_get_term()) == NULL)
	{
		ft_env_destroy(env);
		ft_exit_mess(2);
	}
	ft_get_termcap_function(env);
	ft_handler((unsigned long int)env);
}

int				main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 1)
		ft_exit_mess(1);
	argv[0] = "a";
	if ((env = ft_env_init()) == NULL)
		ft_exit_mess(1);
	if (isatty(0) == 0)
	{
		ft_env_destroy(env);
		ft_exit_mess(4);
	}
	if ((env->fd_tty = open("/dev/tty", O_WRONLY)) == -1)
	{
		ft_env_destroy(env);
		ft_exit_mess(5);
	}
	main_part2(env);
	return (0);
}
