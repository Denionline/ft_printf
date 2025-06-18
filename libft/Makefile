# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME= libft.a

# **************************************************************************** #
#                                     Paths                                    #
# **************************************************************************** #

FILES		+= ft_isalnum
FILES		+= ft_isalpha
FILES		+= ft_isprint
FILES		+= ft_isdigit
FILES		+= ft_isascii
FILES		+= ft_toupper
FILES		+= ft_tolower
FILES		+= ft_atoi
FILES		+= ft_itoa
FILES		+= ft_strncmp
FILES		+= ft_strlen
FILES		+= ft_strlcpy
FILES		+= ft_strlcat
FILES		+= ft_substr
FILES		+= ft_strtrim
FILES		+= ft_strchr
FILES		+= ft_split
FILES		+= ft_strrchr
FILES		+= ft_strnstr
FILES		+= ft_strmapi
FILES		+= ft_strjoin
FILES		+= ft_strdup
FILES		+= ft_striteri
FILES		+= ft_putchar_fd
FILES		+= ft_putstr_fd
FILES		+= ft_putendl_fd
FILES		+= ft_putnbr_fd
FILES		+= ft_calloc
FILES		+= ft_bzero
FILES		+= ft_memcpy
FILES		+= ft_memcmp
FILES		+= ft_memmove
FILES		+= ft_memset
FILES		+= ft_memchr
FILES		+= ft_lstnew
FILES		+= ft_lstadd_front
FILES		+= ft_lstsize
FILES		+= ft_lstlast
FILES		+= ft_lstadd_back
FILES		+= ft_lstdelone
FILES		+= ft_lstclear
FILES		+= ft_lstiter
FILES		+= ft_lstmap


SRCS		= $(addprefix ./, $(addsuffix .c,$(FILES)))
OBJS		= $(addprefix ./, $(addsuffix .o,$(FILES)))


# **************************************************************************** #
#                                     Compiler                                 #
# **************************************************************************** #

cc			= cc
CFLAGS		= -Wall -Wextra -Werror

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

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all