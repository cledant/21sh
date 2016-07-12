/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 21:06:22 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 22:45:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	ft_size_2(wchar_t c, int fd)
{
	unsigned int	tabl[4];
	unsigned int	part[2];

	ft_bzero(part, sizeof(int) * 2);
	tabl[0] = 63;
	tabl[1] = 1984;
	tabl[2] = 128;
	tabl[3] = 49152;
	part[0] = tabl[0] & (unsigned int)c;
	part[1] = tabl[1] & (unsigned int)c;
	part[1] = part[1] << 2;
	part[0] = tabl[2] | part[0];
	part[1] = tabl[3] | part[1];
	part[1] = part[1] >> 8;
	write(fd, &part[1], 1);
	write(fd, &part[0], 1);
}

static void	ft_print_size_4(wchar_t c, unsigned int *tabl, int fd)
{
	unsigned int	part[4];

	ft_bzero(part, sizeof(int) * 4);
	part[0] = tabl[0] & (unsigned int)c;
	part[1] = tabl[1] & (unsigned int)c;
	part[1] = part[1] << 2;
	part[2] = tabl[2] & (unsigned int)c;
	part[2] = part[2] << 4;
	part[3] = tabl[3] & (unsigned int)c;
	part[3] = part[3] << 6;
	part[0] = tabl[4] | part[0];
	part[1] = tabl[5] | part[1];
	part[1] = part[1] >> 8;
	part[2] = tabl[6] | part[2];
	part[2] = part[2] >> 16;
	part[3] = tabl[7] | part[3];
	part[3] = part[3] >> 24;
	write(fd, &part[3], 1);
	write(fd, &part[2], 1);
	write(fd, &part[1], 1);
	write(fd, &part[0], 1);
}

static void	ft_size_4(wchar_t c, int fd)
{
	unsigned int	tabl[8];

	tabl[0] = 63;
	tabl[1] = 4032;
	tabl[2] = 258048;
	tabl[3] = 1835008;
	tabl[4] = 128;
	tabl[5] = 32768;
	tabl[6] = 8388608;
	tabl[7] = 4026531840;
	ft_print_size_4(c, tabl, fd);
}

static void	ft_size_3(wchar_t c, int fd)
{
	unsigned int	tabl[8];
	unsigned int	part[4];

	ft_bzero(part, sizeof(int) * 3);
	tabl[0] = 63;
	tabl[1] = 4032;
	tabl[2] = 61440;
	tabl[3] = 128;
	tabl[4] = 32768;
	tabl[5] = 14680064;
	part[0] = tabl[0] & (unsigned int)c;
	part[1] = tabl[1] & (unsigned int)c;
	part[1] = part[1] << 2;
	part[2] = tabl[2] & (unsigned int)c;
	part[2] = part[2] << 4;
	part[0] = tabl[3] | part[0];
	part[1] = tabl[4] | part[1];
	part[1] = part[1] >> 8;
	part[2] = tabl[5] | part[2];
	part[2] = part[2] >> 16;
	write(fd, &part[2], 1);
	write(fd, &part[1], 1);
	write(fd, &part[0], 1);
}

void		ft_wputchar_fd(wchar_t c, int fd)
{
	size_t			size;

	size = ft_wcharlen(c);
	ft_putnbrendl_fd(size, 1);
	if (size == 1)
		write(fd, &c, 1);
	else if (size == 2)
		ft_size_2(c, fd);
	else if (size == 3)
		ft_size_3(c, fd);
	else if (size == 4)
		ft_size_4(c, fd);
}
