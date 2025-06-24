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
LIBFT		= $(LIBFT_PATH)libft.a


# **************************************************************************** #
#                                     Paths                                    #
# **************************************************************************** #

SRC_PATH		= src/
BUILD_PATH		= .build/
INC_PATH		= include
LIBFT_PATH		= $(INC_PATH)/libft/

# **************************************************************************** #
#                                     Files                                    #
# **************************************************************************** #

FILES			+= ft_printf
FILES			+= ft_printchar
FILES			+= ft_printhexa
FILES			+= ft_printstr
FILES			+= ft_printnbr
FILES			+= ft_printptr
FILES			+= ft_printuint
FILES			+= ft_printflags
FILES			+= ft_handlechar
FILES			+= ft_handlehexa
FILES			+= ft_handlestr
FILES			+= ft_handlenbr
FILES			+= ft_handleptr
FILES			+= ft_handleuint

SRCS			= $(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS			= $(addprefix $(BUILD_PATH), $(addsuffix .o, $(FILES)))

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

all: start auxiliar_libraries $(LIBFT) $(NAME)
	@printf "\n$(C_GREEN)[ft_printf] is ready :D$(C_STD)\n"

start:
	@printf "$(C_MAGENTA)Library [ft_printf]$(C_STD)\n\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): | $(BUILD_PATH)
	@printf "\n$(C_YELLOW)Compile .c files:$(C_STD)\n"
	@TOTAL=$$(echo $(SRCS) | wc -w); \
	CUR=1; \
	for SRC in $(SRCS); do \
	  OBJ=$(BUILD_PATH)$$(basename $$SRC .c).o; \
	  $(CC) $(CFLAGS) -I $(INC_PATH) -c $$SRC -o $$OBJ; \
	  PERC=$$(printf "%d" $$((100 * CUR / TOTAL))); \
	  FILLED=$$(printf "%0.f" $$((20 * PERC / 100))); \
	  EMPTY=$$((20 - FILLED)); \
	  BAR=$$(printf "$(C_GREEN)%*s$(C_STD)" $$FILLED "" | tr " " "#")$$(printf "%*s" $$EMPTY "" | tr " " "."); \
	  printf "\rCompiling [%s] %3d%%" $$BAR $$PERC; \
	  CUR=$$((CUR + 1)); \
	done; \
	printf "\n"; \
	$(AR) $(NAME) $(LIBFT) $(OBJS)

$(BUILD_PATH):
	@mkdir $(BUILD_PATH)

clean:
	@$(RM) $(BUILD_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

auxiliar_libraries:
	@printf "$(C_YELLOW)Checking libraries:$(C_STD)\n"
	@$(MAKE) verify_libft

verify_libft:
	@if test ! -d "$(LIBFT_PATH)"; then $(MAKE) get_libft; \
		else printf "libft: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_libft:
	@echo "Cloning Libft"
	@git clone $(LIBFT_URL) $(LIBFT_PATH)
	@printf "\n$(C_GREEN)libft$(C_STD) successfully downloaded\n"

update_modules:
	@git submodule init
	@git submodule update --recursive --remote
