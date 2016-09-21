# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/09/21 19:40:04 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2 -fsigned-char

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

FRONT_NAME =	ft_read_input.c ft_new_right_node.c ft_hist_destroy.c \
			ft_is_special_char.c ft_btree_insert_node.c ft_hist_search.c \
			ft_btree_cpy_cur.c ft_btree_pushback_node.c ft_btree_pushback_cpy_node.c \
			ft_insert_char.c ft_delete.c ft_btree_delete_node.c ft_backdelete.c \
			ft_btree_backdelete_node.c ft_word_right.c ft_word_left.c ft_line_up.c \
			ft_line_down.c ft_start_copy.c ft_set_copy.c ft_reset_copy.c \
			ft_put_copy.c ft_btree_set_copy_paste.c ft_create_buffer.c \
			ft_realloc_buff.c ft_btree_pushback_copy_pasta_node.c ft_print_buffer.c \
			ft_move_cursor_from_last_buff_to_cur_buff.c ft_insert_data.c \
			ft_cursor_left_buff.c ft_move_cursor_from_cur_buff_to_end_buff.c \
			ft_move_cursor_from_cur_buff_to_before_prompt.c ft_cursor_right_buff.c \
			ft_change_cursor_from_cur_buff_to_end_buff.c ft_home.c ft_end.c \
			ft_change_cursor_from_cur_buff_to_prompt.c ft_btree_clear_content.c \
			ft_enter.c ft_ctrl_d.c ft_ctrl_l.c ft_btree_cut_nodes.c \
			ft_set_inv_buffer.c ft_set_pos_col.c ft_cursor_left_buff_no_set.c \
			ft_cursor_right_buff_no_set.c ft_mline.c ft_convert_btree_to_str.c

FRONT_PATH = ./srcs/front/

INIT_NAME =	main.c ft_get_term.c ft_get_termcap_function.c ft_init_signal.c \
			ft_handler.c ft_env_init.c ft_env_destroy.c ft_prog_main.c \
			ft_change_termsize.c ft_exit_mess.c ft_background.c ft_foreground.c \
			ft_sigint_handler.c

INIT_PATH = ./srcs/init/

SRC_FRONT =	$(addprefix $(FRONT_PATH),$(FRONT_NAME))

SRC_INIT = $(addprefix $(INIT_PATH),$(INIT_NAME))

OBJ_FRONT =	$(FRONT_NAME:.c=.o)

OBJ_INIT =	$(INIT_NAME:.c=.o)

NAME = 21sh

all :	libft $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ_INIT) $(OBJ_FRONT)
	$(CC) $(OBJ_INIT) $(OBJ_FRONT) -o $(NAME) $(CFLAGS) -lft -I$(INCLUDES) -I$(INCLUDES_LIBFT) -L$(LIBFT_PATH) -ltermcap

$(OBJ_INIT) :
	$(CC) -c $(SRC_INIT) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

$(OBJ_FRONT) :
	$(CC) -c $(SRC_FRONT) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ_FRONT) $(OBJ_INIT)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
