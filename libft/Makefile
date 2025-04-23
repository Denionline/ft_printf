# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME= libft.a

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
#                                     Paths                                    #
# **************************************************************************** #

SRC_PATH        = src
BUILD_PATH      = .build
INCLUDE_PATH	= $(SRC_PATH)/include

FT_IS_PATH      = ft_is
FT_TO_PATH      = ft_to
FT_STR_PATH     = ft_str
FT_PUT_PATH     = ft_put
FT_MEM_PATH     = ft_mem
FT_LST_PATH     = ft_lst

FT_IS_FILES     += ft_isalnum
FT_IS_FILES     += ft_isalpha
FT_IS_FILES     += ft_isprint
FT_IS_FILES     += ft_isdigit
FT_IS_FILES     += ft_isascii

FT_TO_FILES     += ft_toupper
FT_TO_FILES     += ft_tolower
FT_TO_FILES     += ft_atoi
FT_TO_FILES     += ft_itoa

FT_STR_FILES        += ft_strncmp
FT_STR_FILES        += ft_strlen
FT_STR_FILES        += ft_strlcpy
FT_STR_FILES        += ft_strlcat
FT_STR_FILES        += ft_substr
FT_STR_FILES        += ft_strtrim
FT_STR_FILES        += ft_strchr
FT_STR_FILES        += ft_split
FT_STR_FILES        += ft_strrchr
FT_STR_FILES        += ft_strnstr
FT_STR_FILES        += ft_strmapi
FT_STR_FILES        += ft_strjoin
FT_STR_FILES        += ft_strdup
FT_STR_FILES        += ft_striteri

FT_PUT_FILES        += ft_putchar_fd
FT_PUT_FILES        += ft_putstr_fd
FT_PUT_FILES        += ft_putendl_fd
FT_PUT_FILES        += ft_putnbr_fd

FT_MEM_FILES        += ft_calloc
FT_MEM_FILES        += ft_bzero
FT_MEM_FILES        += ft_memcpy
FT_MEM_FILES        += ft_memcmp
FT_MEM_FILES        += ft_memmove
FT_MEM_FILES        += ft_memset
FT_MEM_FILES        += ft_memchr

FT_LST_FILES    += ft_lstnew
FT_LST_FILES    += ft_lstadd_front
FT_LST_FILES    += ft_lstsize
FT_LST_FILES    += ft_lstlast
FT_LST_FILES    += ft_lstadd_back
FT_LST_FILES    += ft_lstdelone
FT_LST_FILES    += ft_lstclear
FT_LST_FILES    += ft_lstiter
FT_LST_FILES    += ft_lstmap


SRC_FILES       += $(addprefix $(FT_IS_PATH)/, $(FT_IS_FILES) )
SRC_FILES       += $(addprefix $(FT_TO_PATH)/, $(FT_TO_FILES) )
SRC_FILES       += $(addprefix $(FT_STR_PATH)/, $(FT_STR_FILES) )
SRC_FILES       += $(addprefix $(FT_PUT_PATH)/, $(FT_PUT_FILES) )
SRC_FILES       += $(addprefix $(FT_MEM_PATH)/, $(FT_MEM_FILES) )
SRC_FILES       += $(addprefix $(FT_LST_PATH)/, $(FT_LST_FILES) )

SRCS := $(addprefix $(SRC_PATH)/, $(addsuffix .c,$(SRC_FILES)))
OBJS := $(addprefix $(BUILD_PATH)/, $(addsuffix .o,$(SRC_FILES)))


# **************************************************************************** #
#                                     Compiler                                 #
# **************************************************************************** #

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(INCLUDE_PATH)

# **************************************************************************** #
#                                     Comands                                  #
# **************************************************************************** #

RM          = rm -rf
AR          = ar rcs

# **************************************************************************** #
#                                      Rules                                   #
# **************************************************************************** #

.PHONY: all clean fclean re

all: $(BUILD_PATH) $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@printf "$(COLOR_GREEN)Created archive $(NAME)$(COLOR_DEF_COLOR)\n"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(COLOR_YELLOW)Compiled:$(COLOR_BLUE)$< → $@$(COLOR_DEF_COLOR)\n"

$(BUILD_PATH):
	@mkdir $(BUILD_PATH)
	@mkdir $(BUILD_PATH)/$(FT_IS_PATH)
	@mkdir $(BUILD_PATH)/$(FT_TO_PATH)
	@mkdir $(BUILD_PATH)/$(FT_STR_PATH)
	@mkdir $(BUILD_PATH)/$(FT_PUT_PATH)
	@mkdir $(BUILD_PATH)/$(FT_MEM_PATH)
	@mkdir $(BUILD_PATH)/$(FT_LST_PATH)
	@printf "$(COLOR_CYAN)Created .build folders$(COLOR_DEF_COLOR)\n"
clean:
	@$(RM) $(BUILD_PATH)
	@printf "$(COLOR_RED)Removed $(BUILD_PATH)$(COLOR_DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(COLOR_MAGENTA)Arquive $(NAME) removed!$(COLOR_DEF_COLOR)\n"

re: fclean all