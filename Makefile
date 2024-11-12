# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 19:57:11 by joamiran          #+#    #+#              #
#    Updated: 2024/11/12 21:24:36 by joamiran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Define color codes
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

# Define the executable names
NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
POSTCC = -I $(INC_DIR) -I $(SRC_DIR) \
         -L $(INC_DIR)/lib_ft -lft \

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc
BON_DIR = ./bonus

# List of all .c files in the src directory excluding push_swap.c
SRC_FILES = $(shell find $(SRC_DIR) -name "*.c" ! -name "push_swap.c")

# List of all .c files in the bonus directory excluding checker.c
BON_FILES = $(shell find $(BON_DIR) -name "*.c" ! -name "checker.c")

# Object files for push_swap (all src/ files including push_swap.c)
PUSH_SWAP_OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(OBJ_DIR)/push_swap.o

# Object files for checker (src/ files excluding push_swap.c, and all bonus/ files)
BON_OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(BON_FILES:$(BON_DIR)/%.c=$(OBJ_DIR)/%.o) $(OBJ_DIR)/checker.o

# Rule to compile .c files in src/ into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(SRC_DIR) -I $(BON_DIR) -c $< -o $@ || { echo -e "$(RED)Compilation failed.$(NO_COLOR)"; exit 1; }

# Rule to compile .c files in bonus/ into .o files
$(OBJ_DIR)/%.o: $(BON_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(SRC_DIR) -I $(BON_DIR) -c $< -o $@ || { echo -e "$(RED)Compilation failed.$(NO_COLOR)"; exit 1; }

# Rule to create the push_swap executable
$(NAME): $(PUSH_SWAP_OBJ_FILES)
	@echo  "$(YELLOW)Building $(NAME)...$(NO_COLOR)"
	@make -C $(INC_DIR)/lib_ft > /dev/null 2>&1 || { echo -e "$(RED)Failed to build lib_ft$(NO_COLOR)"; exit 1; }
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ_FILES) \
		$(INC_DIR)/lib_ft/libft.a \
		$(POSTCC) -o $(NAME) || { echo -e "$(RED)Linking failed.$(NO_COLOR)"; exit 1; }
	@echo  "$(GREEN)Compilation complete. Executable: $(NAME)$(NO_COLOR)"

# Rule to create the checker bonus executable (without push_swap.o)
$(BONUS_NAME): clean $(BON_OBJ_FILES)
	@echo "$(YELLOW)Building $(BONUS_NAME)...$(NO_COLOR)"
	@make -C $(INC_DIR)/lib_ft > /dev/null 2>&1 || { echo -e "$(RED)Failed to build lib_ft$(NO_COLOR)"; exit 1; }
	@$(CC) $(CFLAGS) $(BON_OBJ_FILES) \
		$(INC_DIR)/lib_ft/libft.a \
		$(POSTCC) -o $(BONUS_NAME) || { echo -e "$(RED)Linking failed.$(NO_COLOR)"; exit 1; }
	@echo "$(GREEN)Compilation complete. Executable: $(BONUS_NAME)$(NO_COLOR)"

# Build both push_swap and checker
all:  $(NAME)

# 'bonus' rule only compiles checker after cleaning
bonus: $(BONUS_NAME)

# Clean object files
clean:
	@rm -rf $(OBJ_DIR) sources.mk
	@make clean -C $(INC_DIR)/lib_ft > /dev/null 2>&1
	@echo  "$(GREEN)Clean complete.$(NO_COLOR)"

# Full clean including executables
fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C $(INC_DIR)/lib_ft > /dev/null 2>&1 || make clean -C $(INC_DIR)/lib_ft > /dev/null 2>&1
	@echo  "$(GREEN)Full clean complete.$(NO_COLOR)"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus






