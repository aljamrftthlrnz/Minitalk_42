# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 09:50:57 by amirfatt          #+#    #+#              #
#    Updated: 2024/04/08 10:40:51 by amirfatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER= server
CLIENT= client
CC= cc
FLAGS= -g -Wall -Wextra -Werror
LIBFT= cd includes/libft && make
FT_PRINTF= cd includes/ft_printf && make

SERVER_SOURCES= server.c server_utils.c
CLIENT_SOURCES= client.c client_utils.c

SERVER_OBJECTS= $(SERVER_SOURCES:.c=.o)
CLIENT_OBJECTS= $(CLIENT_SOURCES:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJECTS)
	$(LIBFT)
	$(FT_PRINTF)
	$(CC) $(FLAGS) $(SERVER_SOURCES) includes/libft/libft.a includes/ft_printf/libftprintf.a -o $(SERVER)
	@echo "------------Server successfully created------------"

$(CLIENT): $(CLIENT_OBJECTS)
	$(LIBFT)
	$(FT_PRINTF)
	$(CC) $(FLAGS) $(CLIENT_SOURCES) includes/libft/libft.a includes/ft_printf/libftprintf.a -o $(CLIENT)
	@echo "------------Client successfully created------------"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
	cd includes/libft && make clean
	cd includes/ft_printf && make clean
	@echo "------------Object files deletion------------"

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	cd includes/libft && make fclean
	cd includes/ft_printf && make fclean
	@echo "------------Exec files deletion------------"

re: fclean all

.PHONY: all clean fclean re
