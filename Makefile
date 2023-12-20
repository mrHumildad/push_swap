# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 17:46:55 by mnotaro           #+#    #+#              #
#    Updated: 2023/12/02 14:17:40 by mnotaro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	push_swap
CC = cc
INCL = push_swap.h
CFLAGS = -Wall -Werror -Wextra
SRC = main.c swap.c utils.c push.c rotate.c rev_rotate.c checkstack.c getmaxmin.c sort3.c gettarget.c turk.c split_utils.c ft_split.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c Makefile $(INCL)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean clean re
