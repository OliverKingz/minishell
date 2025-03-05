# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 16:53:17 by ozamora-          #+#    #+#              #
#    Updated: 2025/02/12 21:38:50 by ozamora-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# PROJECT
NAME := libft.a

# **************************************************************************** #
# COMPILER
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -MMD -MP

# DEBUG MODE
ifeq ($(DEBUG),1)
	CFLAGS += -g3 -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

# VALGRIND MODE
ifeq ($(VALGRIND),1)
	CFLAGS += -g3
endif

# **************************************************************************** #
# DIRECTORIES
SRC_DIR	:= src/
INC_DIR	:= inc/
OBJ_DIR	:= obj/

# SOURCE SUBDIRECTORIES
IS_DIR	:= is/
LST_DIR	:= lst/
MEM_DIR	:= mem/
PUT_DIR	:= put/
STR_DIR	:= str/
TO_DIR	:= to/
GET_DIR	:= get/

# **************************************************************************** #
# FILES

# SOURCE FILES
IS_FILES	:=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
				ft_islower ft_isupper ft_isspace ft_isdigit_sign_or_space \
				ft_issigned_nbr
LST_FILES	:=	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
				ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
MEM_FILES	:=	ft_memset ft_memcpy ft_memmove ft_memchr ft_memcmp \
				ft_calloc ft_bzero
PUT_FILES	:=	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
				ft_printf ft_putchar ft_putstr ft_putptr \
				ft_putnbr ft_putnbr_base ft_putnbr_unsigned
STR_FILES	:=	ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr \
				ft_strncmp ft_strnstr ft_strdup ft_substr ft_strjoin \
				ft_strtrim ft_split ft_strmapi ft_striteri \
				ft_strrncmp ft_strcmp ft_strjoin_char ft_strtok
TO_FILES	:=	ft_toupper ft_tolower ft_itoa ft_atoi \
				ft_atol
GET_FILES	:=	get_next_line

SRC_FILES	:= $(addprefix $(IS_DIR), $(IS_FILES))
SRC_FILES	+= $(addprefix $(LST_DIR), $(LST_FILES))
SRC_FILES	+= $(addprefix $(MEM_DIR), $(MEM_FILES))
SRC_FILES	+= $(addprefix $(PUT_DIR), $(PUT_FILES))
SRC_FILES	+= $(addprefix $(STR_DIR), $(STR_FILES))
SRC_FILES	+= $(addprefix $(TO_DIR), $(TO_FILES))
SRC_FILES	+= $(addprefix $(GET_DIR), $(GET_FILES))

# INCLUDE FILES
INC_FILES	:= libft get_next_line

# GENERAL FILES
SRCS	:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS	:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS	:= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS	:= $(addprefix $(INC_DIR), $(addsuffix .h, $(INC_FILES)))

# **************************************************************************** #
# COLOURS: BOLD RGBY
BR	= \033[1;31m
BG	= \033[1;32m
BB	= \033[1;34m
BY	= \033[1;33m
BW	= \033[1;37m

# NO COLOR and CLEAR LINE
NC	= \033[0;39m
CL	= \033[2K

# **************************************************************************** #
# ESSENTIAL RULES

# Default rule to create the library
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "%b" "$(CL) -> $(BW)[Libft]:\t\t$(BG)Compilation success\t✅$(NC)\n"

# Rule to compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@printf "%b" "$(CL) -> $(BW)[Libft]:\t\t$(NC)$<\r"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Rule to clean generated files
clean:
	@rm -rf $(OBJ_DIR)
	@printf "%b" "$(CL) -> $(BW)[Libft]:\t\t$(BG)Object files cleaned\t❎$(NC)\n"

# Rule to clean generated files and the executablle
fclean:
	@$(MAKE) clean > /dev/null
	@rm -rf $(NAME)
	@printf "%b" "$(CL) -> $(BW)[Libft]:\t\t$(BG)Exe and objects cleaned\t❎$(NC)\n"

# Rule to recompile from zero. 
re: fclean all

# **************************************************************************** #
# NORM AND DEBUG RULES

# Rule to check if the files pass norminette
norm:
	@norminette $(SRCS) $(INCS)

# Rule to compile object files from source files with debug flags
debug:
	@$(MAKE) -s clean
	@$(MAKE) -s DEBUG=1
	@echo " -> $(BW)[Debug]:\t\t$(BB)Debug mode enabled\t🟦$(NC)"

# Rule to compile with valgrind debug flags
valgrind:
	@$(MAKE) -s clean
	@$(MAKE) -s VALGRIND=1
	@echo " -> $(BW)[Valgrind]:\t\t$(BB)Valgrind mode enabled\t🟦$(NC)"

# **************************************************************************** #
# PERSONAL RULES

# Rule to show compilation and linking commands
show:
	@echo "$(BB)Compilation command:\t$(NC)" \
		"$(CC) $(CFLAGS) -I$(INC_DIR) -c" \
		"$(SRC_DIR)libft.c -o $(OBJ_DIR)libft.o"
	@echo "$(BB)Linking command:\t$(NC)" \
		"$(CC) $(CFLAGS) libft.o -o $(NAME)"
	@echo "$(BB)Cleaning command:\t$(NC)" \
		"rm -rf $(OBJ_DIR) $(NAME)"

# Rule to show all variables being used
info:
	@echo "$(BY)\nozamora's Libft:$(NC)"
	@echo "$(BB)NAME: $(NC)$(NAME)"
	@echo "$(BY)\nCompiler:$(NC)"
	@echo "$(BB)CC: $(NC)$(CC)"
	@echo "$(BB)CFLAGS: $(NC)$(CFLAGS)"
	@echo "$(BY)\nDirectories:$(NC)"
	@echo "$(BB)SRC_DIR: $(NC)$(SRC_DIR)"
	@echo "$(BB)INC_DIR: $(NC)$(INC_DIR)"
	@echo "$(BB)OBJ_DIR: $(NC)$(OBJ_DIR)"
	@echo "$(BY)\nFiles:$(NC)"
	@echo "$(BB)SRC_FILES: $(NC)$(SRC_FILES)"
	@echo "$(BB)INC_FILES: $(NC)$(INC_FILES)"
	@echo "$(BB)SRCS: $(NC)$(SRCS)"
	@echo "$(BB)OBJS: $(NC)$(OBJS)"
	@echo "$(BB)DEPS: $(NC)$(DEPS)"
	@echo "$(BB)INCS: $(NC)$(INCS)"

-include $(DEPS)
.PHONY: all clean fclean re norm show info debug valgrind
.DEFAULT_GOAL := all

# **************************************************************************** #