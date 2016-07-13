/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 11:22:39 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 14:03:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_hist_destroy(t_list **alst)
{
	t_list	**ptr_first;
	t_list	*previous_lst;

	ptr_first = alst;
	*ptr_first = *alst;
	while (*alst != NULL)
	{
		ft_lstdel((t_list **)&(*alst)->content, &ft_lstfree_malloc);
		previous_lst = *alst;
		*alst = (*alst)->next;
		free(previous_lst);
	}
	free(*ptr_first);
	*ptr_first = NULL;
}
