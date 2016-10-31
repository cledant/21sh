/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:04:46 by cledant           #+#    #+#             */
/*   Updated: 2016/10/31 19:39:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_stack_push(const void *src, size_t size, t_stack *stack)
{
	if (stack->cur_size == stack->max_size)
	{
		if (ft_stack_increasesize(stack, STACK_INCREMENT) == 0)
			return (0);
	}
	if ((stack->list[stack->cur_size].elmt = ft_memalloc(size)) == NULL)
		return (0);
	ft_memcpy(stack->list[stack->cur_size].elmt, src, size);
	stack->list[stack->cur_size].size = size;
	stack->cur_size++;
	return (1);
}
