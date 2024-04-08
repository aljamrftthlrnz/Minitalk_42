# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 13:50:16 by amirfatt          #+#    #+#              #
#    Updated: 2023/02/06 15:58:41 by amirfatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_print_utils.c ft_print_ptr.c\
	ft_print_nbr.c ft_print_hex.c

OBJ = $(SRC:.c=.o)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC)
	ar crs $(NAME) $(OBJ)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)
	
re: fclean all