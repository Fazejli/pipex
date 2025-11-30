# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fazejli <fadwazejli58@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 14:41:02 by fadzejli          #+#    #+#              #
#    Updated: 2025/09/16 15:33:24 by fazejli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc -Wall -Wextra -Werror -g
SRCS = ft_bzero.c \
	ft_strchr.c \
	ft_calloc.c \
	ft_memset.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strnstr.c \
	ft_substr.c \
	ft_putstr_fd.c
OBJS = $(SRCS:.c=.o)
INC = libft.h

all : $(NAME)

%.o : %.c $(INC)
	$(CC) -I. -c $< -o $@

$(NAME): $(OBJS) $(INC)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : clean fclean all

.PHONY: clean fclean re
