# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_STD = \033[0;39m
C_GRAY = \033[0;90m
C_RED = \033[0;91m
C_GREEN = \033[0;92m
C_YELLOW = \033[0;93m
C_BLUE = \033[0;94m
C_MAGENTA = \033[0;95m
C_CYAN = \033[0;96m
C_WHITE = \033[0;97m

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft.a


# **************************************************************************** #
#                                     Paths                                    #
# **************************************************************************** #

INC_PATH		= include
SRC_PATH		= src
LIBFT_PATH		= $(include)/libft/

FILES			+= ft_printf.c
FILES			+= ft_printchar.c
FILES			+= ft_printhexa.c
FILES			+= ft_printstr.c
FILES			+= ft_printnbr.c
FILES			+= ft_printptr.c
FILES			+= ft_printuint.c
FILES			+= ft_printflags.c
FILES			+= ft_handlechar.c
FILES			+= ft_handlehexa.c
FILES			+= ft_handlestr.c
FILES			+= ft_handlenbr.c
FILES			+= ft_handleptr.c
FILES			+= ft_handleuint.c

SRC			= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS		= $(SRC:%.c=%.o)

# **************************************************************************** #
#                                     Git                                      #
# **************************************************************************** #

LIBFT_URL		= https://github.com/Denionline/Libft.git

# **************************************************************************** #
#                                     Comands                                  #
# **************************************************************************** #

cc			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
AR			= ar rcs
MAKE		= make --no-print-directory


# **************************************************************************** #
#                                      Rules                                   #
# **************************************************************************** #

.PHONY: all clean fclean re

all: verify_libft $(LIBFT_PATH) $(NAME)

bonus: all

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(LIBFT) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	@(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)

re: fclean all

verify_libft:
	@if test ! -d "$(LIBFT_PATH)"; then $(MAKE) get_libft; \
		else printf "get_next_line: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_libft:
	@echo "Cloning Libft"
	@git clone $(LIBFT_URL) $(LIBFT_PATH)
	@echo "Libft clone successfully downloaded"

update_modules:
	@git submodule init
	@git submodule update --recursive --remote
	@$(MAKE) -C $(LIBFT_PATH)
