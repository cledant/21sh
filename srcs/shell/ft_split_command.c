/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:54:32 by cledant           #+#    #+#             */
/*   Updated: 2016/11/16 22:40:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_create_sub_chain(char ***split, char *cpy_cmd, size_t size,
					size_t i)
{
	if (((*split)[i] = ft_strnew(size)) == NULL)
	{
		ft_strdel_char2(split);
		return (-1);
	}
	if (size != 0)
		ft_memcpy((*split)[i], cpy_cmd, size);
	else
	{
		ft_strdel(split[i]);
		if (((*split)[i] = ft_strnew(1)) == NULL)
		{
			ft_strdel_char2(split);
			return (-1);
		}
		(*split)[i][0] = ' ';
	}
	return (0);
}

static int		ft_skip_quote(char **cmd, size_t *size)
{
	char	*quote;

	quote = *cmd;
	(*cmd)++;
	(*size)++;
	while (**cmd != '\0' && ft_strncmp(*cmd, quote, 1) != 0)
	{
		(*cmd)++;
		(*size)++;
	}
	if (**cmd == '\0')
		return (-1);
	return (0);
}

static void		ft_while(char **cmd, size_t *size)
{
	while (**cmd != '\0')
	{
		if (ft_is_ds_quote(**cmd) == 1)
			if (ft_skip_quote(cmd, size) == -1)
				return ;
		if (**cmd == ';')
			return ;
		(*size)++;
		(*cmd)++;
	}
}

char			**ft_split_command(char *cmd, size_t nb)
{
	char	**split;
	char	*cpy_cmd;
	size_t	i;
	size_t	size;

	if ((split = ft_strnew_char2(nb)) == NULL)
		return (NULL);
	i = 0;
	size = 0;
	cpy_cmd = cmd;
	while (i < nb)
	{
		ft_while(&cmd, &size);
		if (ft_create_sub_chain(&split, cpy_cmd, size, i) == -1)
			ft_handler(20000);
		size = 0;
		i++;
		if (i < nb)
			cmd++;
		cpy_cmd = cmd;
	}
	return (split);
}
