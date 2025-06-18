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
#                                     Compiler                                 #
# **************************************************************************** #

cc			= cc
CFLAGS		= -Wall -Wextra -Werror -fPIC

# **************************************************************************** #
#                                     Comands                                  #
# **************************************************************************** #

RM			= rm -rf
AR			= ar rcs

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

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)

re: fclean all
