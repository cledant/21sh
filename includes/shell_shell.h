/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 20:45:50 by cledant           #+#    #+#             */
/*   Updated: 2016/11/13 15:29:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_SHELL_H
# define SHELL_SHELL_H

void	ft_main_shell(t_env *env);
void	ft_putendl_fd_char2(char **str, int fd);
char	**ft_split_commands(char *cmd);
int		ft_count_commands(char *cmd);
int		ft_is_ds_quote(int c);

#endif
