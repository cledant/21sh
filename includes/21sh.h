/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:04:26 by cledant           #+#    #+#             */
/*   Updated: 2016/07/13 11:32:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_21_H
# define SH_21_H

# include "libft.h"
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>

typedef struct			s_env
{
	char				*term_cap;
	int					fd_tty;
	char				*cl;
	char				*vi;
	char				*ve;
	char				*us;
	char				*ue;
	char				*ho;
	char				*ce;
	char				*mr;
	char				*me;
	char				*nd;
	char				*cr;
	char				*doo;
	int					col;
	int					line;
	t_list				*hist;
	t_list				*cur;
}						t_env;

t_env					*ft_env_init(void);
void					ft_env_destroy(t_env *env);
void					ft_prog_main(t_env *env);
void					ft_exit_mess(int mes);
char					*ft_get_term(void);
void					ft_get_termcap_function(t_env *env);
void					ft_handler(unsigned long int sig);
void					ft_init_signal(void);
void					ft_change_termsize(t_env *env);
void					ft_background(struct termios cpy_term, t_env **env);
void					ft_foreground(t_env *env);
void					ft_read_input(t_env *env);
void					ft_wputchar_char_fd(char buff[4], int fd);
void					ft_list_wputendl_fd(t_list *list, int fd);
t_list					*ft_lstnewpushback(t_list *new, void *buff, size_t size);
t_list					*ft_lstnewpushback_list(t_list *new, t_list *cont);
int						ft_is_special_char(char s[4], t_env *env);
void					ft_hist_destroy(t_list **alst);

#endif
