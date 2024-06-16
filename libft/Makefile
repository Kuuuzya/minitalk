# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuznets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:43:31 by skuznets          #+#    #+#              #
#    Updated: 2024/06/16 09:50:54 by skuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
ft_printf.c ft_putchar.c ft_printstring.c ft_printnumber.c \
ft_printpercent.c ft_printunsignint.c ft_printunsignint.c \
ft_printhex.c ft_printupperhex.c ft_printpointer.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
AR = ar rcs
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS) 

all:		$(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re