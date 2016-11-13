/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:13:18 by cledant           #+#    #+#             */
/*   Updated: 2016/11/13 16:13:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_count_commands(char *cmd)
{
	int		nb;
	char	*last_char;

	nb = 1;
	last_char = NULL;
	if (cmd == NULL)
		return (0);
	while (*cmd != '\0')
	{
		if (last_char != NULL && *last_char == ';' && *cmd == ';')
			return (-1);
		if (ft_is_ds_quote(*cmd) == 1)
		{
			cmd++;
			while (*cmd != '\0' && ft_is_ds_quote(*cmd) == 0)
				cmd++;
			if (*cmd == '\0')
				return (nb);
		}
		if (*cmd == ';')
			nb++;
		last_char = cmd;
		cmd++;
	}
	if (last_char != NULL && *last_char == ';')
		nb--;
	return (nb);
}
