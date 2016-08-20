/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:32:26 by cledant           #+#    #+#             */
/*   Updated: 2016/08/08 12:43:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <term.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

int			main(void)
{
	struct termios	term;
	char			s[4];

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	bzero(s, 4);
	while (1)
	{
		read(0, s, 4);
		printf("\n");
		printf("%d\n", s[0]);
		printf("%d\n", s[1]);
		printf("%d\n", s[2]);
		printf("%d\n", s[3]);
		bzero(s, 4);
	}
	return (0);
}
