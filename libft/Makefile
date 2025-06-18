# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:09:41 by amweyer           #+#    #+#              #
#    Updated: 2025/05/02 12:59:17 by amweyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = 	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_split.c\


BONUS_SRC = 	ft_lstadd_back_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstmap_bonus.c\
				ft_lstnew_bonus.c\
				ft_lstsize_bonus.c\


OBJS := $(SRC:%.c=%.o)

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

NAME = libft.a

CC = cc

CCFLAGS = -Wall -Werror -Wextra

all: $(NAME) 


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	${CC} ${CCFLAGS} -c $< -o $@

bonus: $(BONUS_OBJS) $(OBJS)
	ar rcs $(NAME) $(BONUS_OBJS) $(OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

