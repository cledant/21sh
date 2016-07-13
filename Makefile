# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/07/13 11:32:56 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRC_NAME = main.c ft_get_term.c ft_get_termcap_function.c ft_init_signal.c \
		   ft_handler.c ft_env_init.c ft_env_destroy.c ft_prog_main.c \
		   ft_change_termsize.c ft_exit_mess.c ft_background.c ft_foreground.c \
		   ft_read_input.c ft_wputchar_char_fd.c ft_lstnewpushback.c \
		   ft_list_wputendl_fd.c ft_hist_destroy.c ft_is_special_char.c \
		   ft_lstnewpushback_list.c

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
