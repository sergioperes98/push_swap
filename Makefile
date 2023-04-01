# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 23:21:12 by svilaca-          #+#    #+#              #
#    Updated: 2023/04/01 19:01:14 by svilaca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = operations/push.c operations/swap.c operations/rotate.c operations/reverse_rotate.c \
		push_swap.c list_utils.c initialization.c

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