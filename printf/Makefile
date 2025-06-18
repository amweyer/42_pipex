# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 18:49:39 by amweyer           #+#    #+#              #
#    Updated: 2025/05/03 18:51:10 by amweyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_dispatch.c\
		ft_print_utils.c\
		ft_printf.c\
		
OBJS := $(SRC:%.c=%.o)

NAME = libftprintf.a

CC = cc

CCFLAGS = -Wall -Werror -Wextra

all: $(NAME) 


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	${CC} ${CCFLAGS} -c $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

