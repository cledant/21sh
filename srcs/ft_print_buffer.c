/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:08:48 by cledant           #+#    #+#             */
/*   Updated: 2016/08/19 16:46:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_print_buffer(t_env *env)
{
	size_t 		c;

	c = 0;
	while (c < env->last_buff)
	{
		if ((env->buff)[c] == -1)
			ft_putchar_fd(' ', env->fd_tty);
		else
		{
			ft_putchar_fd((env->buff)[c], env->fd_tty);
		}
		c++;
	}
}
