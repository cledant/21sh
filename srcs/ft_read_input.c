/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:53:26 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 23:20:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_read_input(t_env *env)
{
	char	buff[4];

	while (1)
	{
		ft_bzero(buff, sizeof(char) * 4);
		while (read(0, buff, 4) != 0)
		{
			ft_putnbrendl(buff[0]);
			ft_putnbrendl(buff[1]);
			ft_putnbrendl(buff[2]);
			ft_putnbrendl(buff[3]);
			ft_wputchar_int_fd(buff, env->fd_tty);
			ft_bzero(buff, sizeof(char) * 4);
		}
	}
}
