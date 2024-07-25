# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuznets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:43:31 by skuznets          #+#    #+#              #
#    Updated: 2024/07/25 17:08:56 by skuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_strlen.c ft_isdigit.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_strlcpy.c ft_strlen.c ft_putchar_fd.c

OBJS = $(SRC:.c=.o)
AR = ar rcs
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS) 

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re