/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_mess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 17:37:57 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 15:49:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void			ft_exit_mess(int mes)
{
	if (mes == 1)
		ft_putendl_fd("Error", 2);
	else if (mes == 2)
		ft_putendl_fd("Can't find terminal", 2);
	else if (mes == 3)
		ft_putendl_fd("Please use another terminal", 2);
	else if (mes == 4)
		ft_putendl_fd("Not a terminal", 2);
	else if (mes == 5)
		ft_putendl_fd("Can't open tty", 2);
	exit(-1);
}
