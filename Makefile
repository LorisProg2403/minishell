# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 11:55:17 by lgaume            #+#    #+#              #
#    Updated: 2024/01/24 11:55:21 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC 		= gcc -g
FLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f

LIBFT 			= ./libft/libft.a
READLINE_INC	= -I/opt/homebrew/opt/readline/include
READLINE_LIB	= -L/opt/homebrew/opt/readline/lib -lreadline
INC 			= inc/
SRC_PATH 		= src/
OBJ_PATH 		= obj/

GREEN 	= \033[1;32m
BLUE 	= \033[1;34m
YELLOW 	= \033[1;33m
CYAN 	=	\033[1;36m
MAGENTA = \033[1;35m
RESET 	= \033[0m

SRC 	= minishell
SRC		+= input env/env utils tokens/tokens tokens/tokens_input
SRCS 	= $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC)))
OBJ 	= $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SRCS))

all:					$(NAME)

libft:					$(LIBFT)

libft_clean:
						@make fclean -C ./libft
						@echo "$(YELLOW)Cleaned Libft$(RESET)"

$(LIBFT) :
						@make -C ./libft
						@echo "$(BLUE)[✓] Libft compiled$(RESET)"

$(NAME): 				$(OBJ)
						@$(CC) $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) $(READLINE_LIB) -o $(NAME)
						@echo "$(GREEN)[✓] MINISHELL compiled$(RESET)"

$(OBJ_PATH)%.o: 		$(SRC_PATH)%.c
						@mkdir -p $(@D)
						@$(CC) $(FLAGS) $(READLINE_INC) -I$(INC) -c $< -o $@

norm:
						@clear
						@norminette ./src/* ./inc/*

clean:
						@$(RM) $(OBJ)

fclean:					clean
						@$(RM) $(NAME)
						@echo "$(YELLOW)Cleaned MINISHELL $(RESET)"

re:						fclean all

.PHONY:					all clean fclean re libft libft_clean norm