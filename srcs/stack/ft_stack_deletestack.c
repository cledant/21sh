/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_deletestack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:48:03 by cledant           #+#    #+#             */
/*   Updated: 2016/10/30 19:11:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_stack_deletestack(t_stack **stack)
{
	size_t	i;

	i = 0;
	while (ft_stack_pop(*stack) != 1)
		i++;
	free((*stack)->list);
	free(*stack);
	*stack = NULL;
}
