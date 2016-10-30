/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:27:16 by cledant           #+#    #+#             */
/*   Updated: 2016/10/30 17:13:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_stack_pop(t_stack *stack)
{
	if (stack->cur_size == 0)
		return (0);
	stack->list[stack->cur_size - 1].size = 0;
	free(stack->list[stack->cur_size - 1].elmt);
	stack->list[stack->cur_size - 1].elmt = NULL;
	stack->cur_size--;
	return (1);
}
