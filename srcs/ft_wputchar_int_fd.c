/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_int_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 21:57:10 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 23:21:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_wputchar_int_fd(char buff[4], int fd)
{
	write(fd, &buff[0], 1);
	write(fd, &buff[1], 1);
	write(fd, &buff[2], 1);
	write(fd, &buff[3], 1);
}
