# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 15:01:22 by amweyer           #+#    #+#              #
#    Updated: 2025/06/17 11:36:04 by amweyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
# NAME_BONUS = checker

#include directories
SRC_DIR = src
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj
INC_DIR = include
LIBFT_DIR = libft
PRINTF_DIR = printf

SRC =  $(SRC_DIR)/main.c \
       $(SRC_DIR)/parsing.c \
       $(SRC_DIR)/errors.c \
       $(SRC_DIR)/push.c \
       $(SRC_DIR)/rotate.c \
       $(SRC_DIR)/rrotate.c \
       $(SRC_DIR)/swap.c \
       $(SRC_DIR)/utils.c  \
       $(SRC_DIR)/sort.c   \
       $(SRC_DIR)/stack_utils.c   \
       $(SRC_DIR)/sort_utils.c   \
       $(SRC_DIR)/move_utils.c   \
       $(SRC_DIR)/cost_utils.c   \
       $(SRC_DIR)/sort_back_utils.c   \
	   



# BONUS_SRC =  main.c \
# 		parsing.c \
# 		errors.c \
# 		push.c \
# 		rotate.c \
# 		rev_rotate.c \
# 		swap.c \
# 		push_swap.c \
		
CC = cc

RM = rm -f

CCFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)

LIBS = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf

OBJS := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

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
	
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)
	@echo "${GREEN}Files clean up done.{DEF_COLOR}"
	

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)
	@echo "${GREEN}Clean up done.{DEF_COLOR}"

re: fclean all

# bonus: $(OBJS_BASBO)
# 	$(CC) $(CCFLAGS) $? -o $(NAME)

# everything: $(OBJS_ALL)
# 	$(CC) $(CCFLAGS) $? -o $(NAME)

.PHONY: all clean fclean re bonus everything











