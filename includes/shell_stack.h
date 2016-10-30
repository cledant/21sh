/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:33:08 by cledant           #+#    #+#             */
/*   Updated: 2016/10/30 19:14:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_STACK_H
# define SHELL_STACK_H

t_stack					*ft_stack_newstack(size_t size);
t_stack_elmt			*ft_stack_elmt_newlist(size_t size);
void					ft_stack_elmt_initlist(t_stack_elmt *list,
							size_t size);
int						ft_stack_push(const void *src, size_t size,
							t_stack *stack);
int						ft_stack_pop(t_stack *stack);
t_stack_elmt			*ft_stack_top(const t_stack *stack);
void					ft_stack_deletestack(t_stack **stack);
int						ft_stack_increasesize(t_stack *stack, size_t size);

#endif
