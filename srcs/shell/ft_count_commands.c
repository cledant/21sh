/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:13:18 by cledant           #+#    #+#             */
/*   Updated: 2016/11/16 22:06:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_quote(char **cmd)
{
	char	*quote;

	quote = *cmd;
	(*cmd)++;
	while (**cmd != '\0' && ft_strncmp(*cmd, quote, 1) != 0)
		(*cmd)++;
}

int				ft_count_commands(char *cmd)
{
	int		nb;
	char	*last_char;

	nb = 1;
	last_char = NULL;
	while (*cmd != '\0')
	{
		if (last_char != NULL && *last_char == ';' && *cmd == ';')
			return (-1);
		if (ft_is_ds_quote(*cmd) == 1)
		{
			ft_quote(&cmd);
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
