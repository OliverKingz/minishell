#◉────▣───▢◇▢───▣────◉•◉───▣───▢   Colors:   ▢───▣───◉•◉───▣────▢◇▢───▣───◉#

BLACK   := \033[0;30m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m

CURRENT_COLOR := \033[0;34m
RESET   := \033[0m

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Variables:   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

NAME        := minishell
CC          := cc
CFLAGS      := -Wall -Werror -Wextra -g
RM          := rm -rf

VALGRIND := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no --log-file=test/valgrind_outputs/valgrind_output_$(shell date +%Y%m%d_%H%M%S).log -s

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Libft Variables ▢───▣───◉•◉───▣───▢◇▢───▣──◉#

LIBFT_DIR	:= libft/
LIBFT		:= $(LIBFT_DIR)/libft.a
INCLUDES_LIBFT := -I$(LIBFT_DIR)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢    minishell srcs   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

MINISHELL_SRCS  :=	 check_is_var.c \
					check_line_utils.c \
					check_spaces_line.c \
					check_spaces_line_utils.c \
					check_syntax_error_line.c \
					check_syntax_error_token.c \
					check_type_tokens.c \
					check_type_tokens_utils.c \
					ckeck_quote_utils.c \
					exe_cmd.c \
					free_utils.c \
					ft_tokeniser.c \
					list_utils.c \
					main.c \
					test_funcionts.c \
					test_utils.c \
					token_utils.c \
					tokenize_with_quotes.c \
					utils.c \
					heredoc.c \
					#signals.c \
					#check_reserved_words.c \

MINISHELL_OBJS  := $(MINISHELL_SRCS:.c=.o)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢     rules      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DEPS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(MINISHELL_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(MINISHELL_OBJS) -L$(LIBFT_DIR) -lreadline -lft $(INCLUDES_LIBFT) 
	@echo "$(CURRENT_COLOR) ✅ $(NAME) created.\n$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_LIBFT) -c $< -o $@ 

clean:
	$(RM) $(MINISHELL_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(CURRENT_COLOR)🧹 Object files cleaned.\n$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(CURRENT_COLOR) 🧹 $(NAME) and libft.a: binary cleaned.\n$(RESET)"

re: fclean all

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Valgrind   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

valgrind: all

	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──Running Valgrind..──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──$(RESET)"
	@-$(VALGRIND) ./$(NAME)
	@test/hs_files/./open_valgrind_log.sh
	@echo "$(CURRENT_COLOR)➵⤐╌╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣── Valgrind completed. Check valgrind_output.log for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"
	
clean_valgrind:
	test/hs_files/./clean_valgrind.sh

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Test    ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

test: all
#revisar que *.sh tienen permisos en /test/sh_files/
	@echo "Ensuring all scripts in /test/hs_files/ have execution permissions..."
	@find test/hs_files/ -name "*.sh" ! -perm -111 -exec chmod +x {} \;
#startr test
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Starting test: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@test/hs_files/./test_minishell.sh
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── End of test. ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"

clean_test:
	test/hs_files/./clean_test.sh

#◉───▣───▢◇▢───▣───◉•◉───▣───▢Norminette ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

norm:
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Checking Norminette: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@norminette $(MINISHELL_SRCS) minishell.h
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Norminette completed. Check your output for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"

#◉───▣───▢◇▢───▣───◉•◉───▣───▢  Format ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

format: 
	c_formatter_42 $(MINISHELL_SRCS) minishell.h

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Phony targets ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

.PHONY: all clean fclean re format norm valgrind test clean_valgrind clean_test 