# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 14:07:58 by fazejli           #+#    #+#              #
#    Updated: 2025/07/16 13:55:31 by fadzejli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc -Wall -Wextra -Werror -g
SRCS = srcs/pipex.c srcs/utils.c
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
INC = pipex.h

%.o : %.c
	$(CC) -I. -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	make -C libft
	make clean -C libft
	$(CC) $(OBJS) $(LIBFT) -o $@

clean :
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf ${LIBFT}

re: fclean all

.PHONY : all clean flcean re