/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_newstack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:54:26 by cledant           #+#    #+#             */
/*   Updated: 2016/10/30 15:32:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_stack		*ft_stack_newstack(size_t size)
{
	t_stack			*newstack;
	t_stack_elmt	*newlst;

	if ((newstack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	if ((newlst = ft_stack_elmt_newlist(size)) == NULL)
	{
		free(newstack);
		return (NULL);
	}
	newstack->list = newlst;
	newstack->max_size = size;
	newstack->cur_size = 0;
	return (newstack);
}
