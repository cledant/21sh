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
	size_t			i;
	char			*s;
	char			*s_check;
	t_stack_elmt	*elmt;

	i = 0;
	while (ft_stack_pop(stack) == 1)
		i++;
	while (to_check != NULL)
	{
		s = to_check->content;
		if (stack->cur_size != 0)
		{
			elmt = ft_stack_top(stack);
			s_check = elmt->elmt;
			if (s_check[0] == s[0])
				ft_stack_pop(stack);
		}
		else if (stack->cur_size == 0 && (s[0] == 34 || s[0] == 39))
			ft_stack_push(s, 1, stack);
		to_check = to_check->right;
	}
	if (stack->cur_size == 0)
		return (1);
	return (0);
}
