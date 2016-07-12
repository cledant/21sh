/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_buffer_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 20:01:36 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 20:05:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_wputchar_buffer_fd(char s[4], int fd)
{
	write(fd, &s[0], 1);
	write(fd, &s[1], 1);
	write(fd, &s[2], 1);
	write(fd, &s[3], 1);
}
