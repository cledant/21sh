/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_term_cap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:45:05 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 19:46:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_get_term(void)
{
	char			*term;
	char			*term_cap;

	term_cap = ft_strnew(2048);
	if ((term = getenv("TERM")) != NULL && tgetent(term_cap, term) == 1)
		return (term_cap);
	ft_strdel(&term_cap);
	return (NULL);
}
