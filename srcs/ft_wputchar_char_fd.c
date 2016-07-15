/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_char_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 09:36:42 by cledant           #+#    #+#             */
/*   Updated: 2016/07/15 10:52:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_wputchar_char_fd(char buff[4], int fd)
{
	write(fd, &buff[0], 1);
	write(fd, &buff[1], 1);
	write(fd, &buff[2], 1);
	write(fd, &buff[3], 1);
}
