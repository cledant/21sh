/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:08:48 by cledant           #+#    #+#             */
/*   Updated: 2016/08/19 13:12:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_print_buffer(t_env *env)
{
	size_t 		c;

	c = 0;
	while (c < env->last_buff)
	{
		if (env->buff[c] == -1)
			ft_putchar(" ");
		else
			ft_putchar(env->buff[c]);
		c++;
	}
}
