/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:54:32 by cledant           #+#    #+#             */
/*   Updated: 2016/11/13 20:09:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_split_command(char *cmd, size_t nb)
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
		while (*cmd != '\0')
		{
			if (ft_is_ds_quote(*cmd) == 1)
			{
				while (*cmd != '\0' && ft_is_ds_quote(*cmd) == 0)
					cmd++;
			}
			if (*cmd == ';')
				break ;
			size++;
			cmd++;
		}
		if ((split[i] = ft_strnew(size)) == NULL)
		{
			ft_strdel_char2(&split);
			ft_handler(20000);
		}
		if (size != 0)
			ft_memcpy(split[i], cpy_cmd, size);
		else
		{
			ft_strdel(&(split[i]));
			if ((split[i] = ft_strnew(1)) == NULL)
			{
				ft_strdel_char2(&split);
				ft_handler(20000);		
			}
			split[i][0] = ' ';
		}
		size = 0;
		i++;
		if (i < nb)
			cmd++;
		cpy_cmd = cmd;
	}
	return (split);
}
