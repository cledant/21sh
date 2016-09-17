/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 18:24:31 by cledant           #+#    #+#             */
/*   Updated: 2016/09/17 18:45:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_INIT_H
# define SHELL_INIT_H

t_env	*ft_env_init(void);
void	ft_env_destroy(t_env *env);
void	ft_prog_main(t_env *env);
void	ft_exit_mess(int mes);
char	*ft_get_term(void);
void	ft_get_termcap_function(t_env *env);
void	ft_handler(unsigned long int sig);
void	ft_init_signal(void);
void	ft_change_termsize(t_env *env);
void	ft_background(struct termios cpy_term, t_env **env);
void	ft_foreground(t_env *env);
void	ft_sigint_handler(t_env *env);

#endif
