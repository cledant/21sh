/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:40:46 by cledant           #+#    #+#             */
/*   Updated: 2016/10/30 17:10:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_stack_elmt	*ft_stack_top(const t_stack *stack)
{
	if (stack->cur_size == 0)
		return (NULL);
	return (&(stack->list[stack->cur_size - 1]));
}
