/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewpushback_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 10:38:02 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 12:07:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_list		*ft_lstnewpushback_list(t_list *new, t_list *cont)
{
	t_list	*after;

	if (new == NULL)
	{
		if ((new = ft_lstnew(NULL, 0)) == NULL)
			return (NULL);
		new->content = cont;
	}
	else
	{
		if ((after = ft_lstnew(NULL, 0)) == NULL)
			return (NULL);
		after->content = cont;
		ft_lstpushback(new, after);
	}
	return (new);
}
