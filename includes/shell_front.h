/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_front.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 18:25:25 by cledant           #+#    #+#             */
/*   Updated: 2016/11/01 16:54:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_FRONT_H
# define SHELL_FRONT_H

void		ft_read_input(t_env *env);
t_btree		*ft_btree_pushback_node(t_btree *node, char s[4]);
t_btree		*ft_btree_insert_node(t_env *env, char s[4]);
t_btree		*ft_btree_cpy_cur(t_btree *previous, t_env *env);
t_btree		*ft_btree_pushback_cpy_node(t_btree *src, t_btree *cpy, t_env *env);
void		ft_btree_clear_content(t_btree **root);
int			ft_is_special_char(char s[4], t_env *env);
void		ft_hist_destroy(t_btree **root);
int			ft_hist_search(t_env *env, int where);
t_btree		*ft_new_right_node(t_env *env);
void		ft_insert_char(char s[4], t_env *env);
int			ft_delete(t_env *env);
void		ft_btree_delete_node(t_env *env);
int			ft_backdelete(t_env *env);
void		ft_btree_backdelete_node(t_env *env);
int			ft_word_right(t_env *env);
int			ft_word_left(t_env *env);
int			ft_line_up(t_env *env);
int			ft_line_down(t_env *env);
int			ft_start_copy(t_env *env);
int			ft_set_copy(t_env *env, int cut);
int			ft_reset_copy(t_env *env, size_t disp);
int			ft_put_copy(t_env *env);
t_btree		*ft_btree_set_copy_paste(t_btree *first, t_btree *end, int len);
t_btree		*ft_btree_pushback_copy_pasta_node(t_btree *src, t_btree *cpy,
				size_t sign);
void		ft_insert_data(char s[4], t_env *env);
void		ft_create_buffer(t_env *env);
void		ft_realloc_buff(t_env *env);
void		ft_print_buffer(t_env *env);
void		ft_move_cursor_from_last_buff_to_cur_buff(t_env *env);
void		ft_move_cursor_from_cur_buff_to_end_buff(t_env *env);
void		ft_move_cursor_from_cur_buff_to_before_prompt(t_env *env);
int			ft_change_cursor_from_cur_buff_to_end_buff(t_env *env);
int			ft_change_cursor_from_cur_buff_to_prompt(t_env *env);
int			ft_cursor_left_buff(t_env *env);
int			ft_cursor_right_buff(t_env *env);
int			ft_home(t_env *env);
int			ft_end(t_env *env);
int			ft_enter(t_env *env);
int			ft_ctrl_d(t_env *env);
int			ft_ctrl_l(t_env *env);
void		ft_btree_cut_nodes(t_env *env, int len);
void		ft_set_inv_buffer(t_env *env);
void		ft_set_pos_col(t_env *env);
int			ft_cursor_left_buff_no_set(t_env *env);
int			ft_cursor_right_buff_no_set(t_env *env);
int			ft_mline(t_env *env);
char		*ft_convert_btree_to_str(t_btree *root, size_t size);
void		ft_cursor_case_one(t_env *env, size_t *c);
void		ft_cursor_case_two(t_env *env, size_t *c);
void		ft_cursor_case_three(t_env *env, size_t *c);
int			ft_check_quotes(t_stack *stack, t_btree *to_check);
int			ft_new_right_node_error_quote(t_env *env, int type);
void		ft_add_to_err_quote(t_env *env);
void		ft_clear_err_quote(t_env *env);

#endif
