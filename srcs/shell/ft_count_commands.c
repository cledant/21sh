/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:13:18 by cledant           #+#    #+#             */
/*   Updated: 2016/11/16 21:12:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_count_commands(char *cmd)
{
	int		nb;
	char	*last_char;
	char	*quote;

	nb = 1;
	last_char = NULL;
	quote = NULL;
	while (*cmd != '\0')
	{
		if (last_char != NULL && *last_char == ';' && *cmd == ';')
			return (-1);
		if (ft_is_ds_quote(*cmd) == 1)
		{
			quote = cmd;
			cmd++;
			while (*cmd != '\0' && ft_strncmp(cmd, quote, 1) != 0)
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
