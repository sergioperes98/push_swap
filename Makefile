# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svilaca- <svilaca-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 23:21:12 by svilaca-          #+#    #+#              #
#    Updated: 2023/05/09 21:07:37 by svilaca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	push.c swap.c rotate.c reverse_rotate.c \
		little_sort.c list_utils.c initializer.c \
		mean.c cost.c cost2.c

OBJS = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJS) 
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re