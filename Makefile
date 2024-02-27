# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamraoui <bamraoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 10:14:48 by bamraoui          #+#    #+#              #
#    Updated: 2024/02/27 18:43:32 by bamraoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADER = pipex.h
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f
# AR = ar -crs
SRCF = pipex.c \
	pipex_utils.c \
	print_error.c \
	ft_split.c \
	ft_strjoin.c \

OBJF = $(SRCF:.c=.o)

all = $(NAME)

$(NAME): $(OBJF)
	$(CC) $(CFLAGS) $(OBJF) -o ${NAME}

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c  $< -o $@

clean: 
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re