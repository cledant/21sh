/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_elmt_initlist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:50:13 by cledant           #+#    #+#             */
/*   Updated: 2016/10/30 17:45:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

inline void		ft_stack_elmt_initlist(t_stack_elmt *list, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		list[i].elmt = NULL;
		list[i].size = 0;
		i++;
	}
}
