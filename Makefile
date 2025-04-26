# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #


COLOR_DEF_COLOR = \033[0;39m
COLOR_GRAY = \033[0;90m
COLOR_RED = \033[0;91m
COLOR_GREEN = \033[0;92m
COLOR_YELLOW = \033[0;93m
COLOR_BLUE = \033[0;94m
COLOR_MAGENTA = \033[0;95m
COLOR_CYAN = \033[0;96m
COLOR_WHITE = \033[0;97m

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT_NAME	= libft.a

# **************************************************************************** #
#                                     Paths                                    #
# **************************************************************************** #

SRC_PATH		= .
LIBFT_PATH		= libft

FILES		+= ft_printf.c
FILES		+= ft_puthexa_fd.c

SRC			= $(addprefix ./, $(FILES))
OBJS		= $(SRC:%.c=%.o)

# **************************************************************************** #
#                                     Compiler                                 #
# **************************************************************************** #

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# **************************************************************************** #
#                                     Comands                                  #
# **************************************************************************** #

RM          = rm -rf
AR          = ar rcs

# **************************************************************************** #
#                                      Rules                                   #
# **************************************************************************** #

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)/$(LIBFT_NAME) $(SRC_PATH)
	@mv $(LIBFT_NAME) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@printf "$(COLOR_GREEN)Created archive $(NAME)$(COLOR_DEF_COLOR)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(COLOR_YELLOW)Compiled:$(COLOR_BLUE)$< → $@$(COLOR_DEF_COLOR)\n"

clean:
	@make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)
	@printf "$(COLOR_RED)Removed $(OBJS)$(COLOR_DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@printf "$(COLOR_MAGENTA)Arquive $(NAME) removed!$(COLOR_DEF_COLOR)\n"

re: fclean all