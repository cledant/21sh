/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 18:38:37 by cledant           #+#    #+#             */
/*   Updated: 2016/10/31 21:05:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>

void	test_print_stack(t_stack *stack)
{
	size_t	i;
	size_t	*value;

	i = 0;
	while (i < stack->cur_size)
	{
		if (stack->list[i].elmt != NULL)
		{
			value = stack->list[i].elmt;
			printf("ELMT %zu : ELMT_VALUE  = %zu\n", i, *value);
			printf("ELMT %zu : ELMT_SIZE  = %zu\n", i, (size_t)stack->list[i].size);
		}
		i++;
	}
}

int		main(void)
{
	t_stack			*stack;
	t_stack_elmt	*top;
	size_t			i;
	size_t			test;

	test = 300;
	stack = ft_stack_newstack(10);
	while (i <= 15)
	{
		printf("===============\n");
		printf("i = %zu\n", i);
		printf("Return de push : %d\n", ft_stack_push(&i, sizeof(size_t),
			stack));
		i++;
		test_print_stack(stack);
		printf("CUR_SIZE = %zu\n", stack->cur_size);
		printf("MAX_SIZE = %zu\n", stack->max_size);
		printf("===============\n");
	}
	printf("===============\n");
	printf("MODIF TOP\n");
	top = ft_stack_top(stack);
	ft_memcpy(top->elmt, &test, sizeof(size_t));
	ft_memcpy(&(top->size), &test, sizeof(size_t));
	test_print_stack(stack);
	printf("CUR_SIZE = %zu\n", stack->cur_size);
	printf("MAX_SIZE = %zu\n", stack->max_size);
	printf("===============\n");
	printf("===============\n");
	printf("TRY POP + MODIF TOP 2\n");
	ft_stack_pop(stack);
	test = 100;
	top = ft_stack_top(stack);
	ft_memcpy(top->elmt, &test, sizeof(size_t));
	ft_memcpy(&(top->size), &test, sizeof(size_t));
	test_print_stack(stack);
	printf("CUR_SIZE = %zu\n", stack->cur_size);
	printf("MAX_SIZE = %zu\n", stack->max_size);
	printf("===============\n");
	printf("TRY DELETE STACK\n");
	ft_stack_deletestack(&stack);
	if (stack == NULL)
		printf("DELETE STACK == OK !\n");
	return (0);
}
