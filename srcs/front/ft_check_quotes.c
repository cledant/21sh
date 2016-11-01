/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:36:18 by cledant           #+#    #+#             */
/*   Updated: 2016/11/01 16:55:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_check_quotes(t_stack *stack, t_btree *to_check)
{
	size_t		i;

	i = 0;
	while (ft_stack_pop(stack) == 1)
		i++;
	if (to_check == NULL)
		return (0);
	if (stack->cur_size == 0)
		return (1);
	return (0);
}
