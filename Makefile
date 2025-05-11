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
INCLUDE_PATH	= include

FILES		+= ft_printf.c
FILES		+= ft_printhexa.c
FILES		+= ft_printstr.c
FILES		+= ft_printchar.c
FILES		+= ft_printnbr.c
FILES		+= ft_printptr.c
FILES		+= ft_printuint.c

FILES		+= ft_printflags.c
FILES		+= ft_handlechar.c
FILES		+= ft_handlehexa.c
FILES		+= ft_handlestr.c
FILES		+= ft_handlenbr.c
FILES		+= ft_handleptr.c
FILES		+= ft_handleuint.c

SRC			= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS		= $(SRC:%.c=%.o)

# **************************************************************************** #
#                                     Compiler                                 #
# **************************************************************************** #

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INC			= -I$(INCLUDE_PATH)

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

bonus: all

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)/$(LIBFT_NAME) .
	@mv $(LIBFT_NAME) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@printf "$(COLOR_GREEN)Created archive $(COLOR_YELLOW)$(NAME)$(COLOR_DEF_COLOR)\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "$(COLOR_YELLOW)Compiled: $(COLOR_BLUE)$< → $@$(COLOR_DEF_COLOR)\n"

m:
	@clear
	@$(CC) $(CFLAGS) main.c $(NAME)
	@./a.out
	@$(RM) a.out
msf:
	@clear
	@$(CC) main.c $(NAME)
	@./a.out
	@$(RM) a.out

val:
	@clear
	@$(CC) $(CFLAGS) main.c $(NAME)
	@valgrind ./a.out
	@$(RM) a.out

valsf:
	@clear
	@$(CC) main.c $(NAME)
	@valgrind ./a.out
	@$(RM) a.out
gdb:
	@$(CC) main.c $(NAME) -g
	@gdb ./a.out

clean:
	@make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)
	@printf "$(COLOR_RED)Removed $(OBJS)$(COLOR_DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@printf "$(COLOR_MAGENTA)Arquive $(NAME) removed!$(COLOR_DEF_COLOR)\n"

re: fclean all
