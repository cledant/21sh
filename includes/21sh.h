/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:04:26 by cledant           #+#    #+#             */
/*   Updated: 2016/08/21 13:49:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_21_H
# define SH_21_H

# include "libft.h"
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>

# ifndef SIGEMT
#  define SIGEMT 20000
# endif

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
	char				*cd;
	char				*up;
	char				*le;
	int					col;
	int					line;
	t_btree				*first;
	t_btree				*last;
	t_btree				*cur;
	t_btree				*cur_il;
	size_t				cur_char;
	size_t				first_char;
	size_t				last_char;
	size_t				mode_copy;
	t_btree				*begin_copy;
	size_t				begin_cur_char;
	t_btree				*cpy;
	size_t				buff_size;
	char				*buff;
	size_t				too_small;
	size_t				cur_buff;
	size_t				last_buff;
	size_t				cur_clean;
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
/* SHELL */
void					ft_read_input(t_env *env); //ok
void					ft_wputchar_char_fd(char buff[4], int fd);
void					ft_btree_wputendl_fd(t_btree *root, int fd);
void					ft_btree_wputstr_fd(t_btree *root, int fd);
t_btree					*ft_btree_pushback_node(t_btree *node, char s[4]); //ok
t_btree					*ft_btree_insert_node(t_env *env, char s[4]); //ok
t_btree					*ft_btree_cpy_cur(t_btree *previous, t_env *env);
t_btree					*ft_btree_pushback_cpy_node(t_btree *src,
							t_btree *cpy, t_env *env);
void					ft_btree_clear_content(t_btree **root);
int						ft_is_special_char(char s[4], t_env *env); //ok
void					ft_hist_destroy(t_btree **root); //ok
void					ft_reprint_prompt(char s[4], t_env *env);
int						ft_hist_search(t_env *env, int where);
void					ft_delete_cur_prompt(t_env *env);
void					ft_move_to_cur_prompt(t_env *env);
t_btree					*ft_new_right_node(t_env *env); //ok
void					ft_print_n_insert_data(char s[4], t_env *env);
int						ft_cursor_left(t_env *env);
void					ft_cursor_left_prompt(t_env *env);
int						ft_cursor_right(t_env *env);
void					ft_cursor_right_prompt(t_env *env);
void					ft_insert_char(char s[4], t_env *env); //ok
void					ft_cursor_moveback_to_cur(t_env *env);
int						ft_cursor_move_to_end(t_env *env);
int						ft_cursor_move_to_end_prompt(t_env *env);
int						ft_cursor_move_to_orig(t_env *env);
int						ft_delete(t_env *env);
void					ft_btree_delete_node(t_env *env);
int						ft_backdelete(t_env *env);
void					ft_btree_backdelete_node(t_env *env);
void					ft_sigint_handler(t_env *env);
int						ft_word_right(t_env *env);
int						ft_word_left(t_env *env);
int						ft_line_up(t_env *env);
int						ft_line_down(t_env *env);
int						ft_start_copy(t_env *env);
int						ft_set_copy(t_env *env);
int						ft_reset_copy(t_env *env, size_t disp);
int						ft_put_copy(t_env *env);
t_btree					*ft_btree_set_copy_paste(t_btree *first, int len);
t_btree					*ft_btree_pushback_copy_pasta_node(t_btree *src,
							t_btree *cpy, size_t sign);
void					ft_reprint_inverted_selection(t_env *env);
void					ft_print_line(t_env *env);
void					ft_insert_data(char s[4], t_env *env); //ok
void					ft_create_buffer(t_env *env); //ok
void					ft_realloc_buff(t_env *env); //ok
void					ft_print_buffer(t_env *env); //ok
void					ft_clear_line(t_env *env); //ok
void					ft_cursor_left_clean(t_env *env); //ok
void					ft_move_cursor_from_last_buff_to_cur_buff(t_env *env); //ok
void					ft_move_cursor_from_cur_buff_to_end_buff(t_env *env); //ok
void					ft_move_cursor_from_cur_buff_to_before_prompt(t_env *env); //ok
int						ft_cursor_left_buff(t_env *env); //ok
int						ft_cursor_right_buff(t_env *env); //ok

#endif
