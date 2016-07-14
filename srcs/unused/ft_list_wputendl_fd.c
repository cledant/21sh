/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_wputendl_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 09:55:01 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 09:55:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_list_wputendl_fd(t_list *list, int fd)
{
	size_t	size;

	size = 0;
	while (list != NULL)
	{
		ft_wputchar_char_fd(list->content, fd);
		list = list->next;
		size++;
	}
	if (size != 0)
		write(fd, "\n", 1);
}
