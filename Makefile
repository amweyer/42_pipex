# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 15:01:22 by amweyer           #+#    #+#              #
#    Updated: 2025/07/07 11:59:47 by amweyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

#include directories
SRC_DIR = src
BONUS_DIR = bonus_src
GNL_DIR = get_next_line

OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj

INC_DIR = include
INC_BONUS_DIR = bonus_include


LIBFT_DIR = libft
PRINTF_DIR = printf

SRC =  $(SRC_DIR)/main.c \
       $(SRC_DIR)/parsing.c \
       $(SRC_DIR)/free.c \
       $(SRC_DIR)/pipe.c \
       $(SRC_DIR)/pipe_utils.c \
       $(SRC_DIR)/pipe_init.c \

BONUS_SRC = $(BONUS_DIR)/main_bonus.c \
			$(BONUS_DIR)/parsing_bonus.c \
			$(BONUS_DIR)/free_bonus.c \
			$(BONUS_DIR)/pipe_bonus.c \
			$(BONUS_DIR)/pipe_utils_bonus.c \
			$(BONUS_DIR)/pipe_init_bonus.c \
			$(BONUS_DIR)/get_next_line_utils_bonus.c \
			$(BONUS_DIR)/get_next_line_bonus.c \


EVERYTHING_SRC = $(SRC) $(BONUS_SRC)

CC = cc

RM = rm -f

CCFLAGS = -g3 -Wall -Werror -Wextra

CPPFLAGS = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)
CPPFLAGS_BONUS = -I $(INC_BONUS_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GNL_DIR)

LIBS = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf

OBJS := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS := $(BONUS_SRC:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m

all: $(NAME)


$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(CC) $(CCFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "${GREEN}Compilation of $(NAME) done.${DEF_COLOR}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CCFLAGS) $(CPPFLAGS_BONUS) -c $< -o $@
	
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS) 
	@echo "${GREEN}Files clean up done.{DEF_COLOR}"
	

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(BONUS_OBJS) 
	@echo "${GREEN}Clean up done.{DEF_COLOR}"

re: fclean all

bonus: $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(CC) $(CCFLAGS) $(BONUS_OBJS) $(LIBS) -o $(NAME_BONUS)
	@echo "${GREEN}Compilation of $(NAME_BONUS) done.${DEF_COLOR}"

.PHONY: all clean fclean re bonus everything











