# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/08/20 12:38:11 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRC_NAME = main.c ft_get_term.c ft_get_termcap_function.c ft_init_signal.c \
		   ft_handler.c ft_env_init.c ft_env_destroy.c ft_prog_main.c \
		   ft_change_termsize.c ft_exit_mess.c ft_background.c ft_foreground.c \
		   ft_read_input.c ft_wputchar_char_fd.c ft_new_right_node.c \
		   ft_btree_wputendl_fd.c ft_hist_destroy.c ft_is_special_char.c \
		   ft_btree_insert_node.c ft_hist_search.c ft_btree_wputstr_fd.c \
		   ft_delete_cur_prompt.c ft_btree_cpy_cur.c ft_btree_pushback_node.c \
		   ft_btree_pushback_copy_node.c ft_print_n_insert_data.c ft_insert_char.c \
		   ft_cursor_left.c ft_cursor_right.c ft_cursor_moveback_to_cur.c \
		   ft_cursor_move_to_orig.c ft_cursor_move_to_end.c ft_delete.c \
		   ft_cursor_left_prompt.c ft_move_to_cur_prompt.c ft_btree_delete_node.c \
		   ft_backdelete.c ft_btree_backdelete_node.c ft_sigint_handler.c \
		   ft_word_right.c ft_word_left.c ft_line_up.c ft_cursor_right_prompt.c \
		   ft_cursor_move_to_end_prompt.c ft_line_down.c ft_start_copy.c \
		   ft_set_copy.c ft_reset_copy.c ft_put_copy.c ft_btree_set_copy_paste.c \
		   ft_btree_pushback_copy_pasta_node.c ft_reprint_inverted_selection.c \
		   ft_print_line.c \
		   ft_create_buffer.c ft_realloc_buff.c ft_print_buffer.c ft_clear_line.c \
		   ft_cursor_left_clean.c ft_move_cursor_to_cur_buff.c ft_insert_data.c \
		   ft_cursor_left_new.c

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =	$(SRC_NAME:.c=.o)

NAME = 21sh

all :	libft $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -I$(INCLUDES) -I$(INCLUDES_LIBFT) -L$(LIBFT_PATH) -ltermcap

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
