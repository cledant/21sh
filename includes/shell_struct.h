/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 18:23:05 by cledant           #+#    #+#             */
/*   Updated: 2016/11/01 16:50:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_STRUCT_H
# define SHELL_STRUCT_H

typedef struct			s_stack_elmt
{
	void				*elmt;
	size_t				size;
}						t_stack_elmt;

typedef struct			s_stack
{
	t_stack_elmt		*list;
	size_t				max_size;
	size_t				cur_size;
}						t_stack;

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
	char				*sr;
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
	t_btree				*end_copy;
	size_t				begin_cur_char;
	t_btree				*cpy;
	size_t				buff_size;
	char				*buff;
	size_t				mline;
	size_t				cur_buff;
	size_t				last_buff;
	char				*inv_buff;
	size_t				pos_col;
	size_t				pos_line;
	char				*cmd_line;
	char				**env;
	t_stack				*stack_quote;
}						t_env;

#endif
