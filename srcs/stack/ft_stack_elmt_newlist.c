/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_elmt_newlist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:39:34 by cledant           #+#    #+#             */
/*   Updated: 2016/10/30 17:46:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

inline t_stack_elmt		*ft_stack_elmt_newlist(size_t size)
{
	t_stack_elmt	*list;

	if ((list = (t_stack_elmt *)malloc(size * sizeof(t_stack_elmt))) == NULL)
		return (NULL);
	ft_stack_elmt_initlist(list, size);
	return (list);
}
