/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_increasesize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 17:47:33 by cledant           #+#    #+#             */
/*   Updated: 2016/11/01 15:20:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void	ft_stack_elmt_cpy(t_stack_elmt *dst,
						const t_stack_elmt *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i].elmt = src[i].elmt;
		dst[i].size = src[i].size;
		i++;
	}
}

int					ft_stack_increasesize(t_stack *stack, size_t size)
{
	t_stack_elmt	*newlist;

	if ((newlist = (t_stack_elmt *)malloc((stack->max_size + size) *
			sizeof(t_stack_elmt))) == NULL)
		return (0);
	ft_stack_elmt_cpy(newlist, stack->list, stack->cur_size);
	free(stack->list);
	stack->list = newlist;
	stack->max_size += size;
	return (1);
}
