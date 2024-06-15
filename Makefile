# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuznets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 19:22:09 by skuznets          #+#    #+#              #
#    Updated: 2024/06/15 19:22:15 by skuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re