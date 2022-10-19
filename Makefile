# Name ==========================================

NAME := so_long.a

# Dirs ==========================================

SRC_DIR := srcs
INC_DIR := include
LIB_DIR := lib
BIN_DIR := .

# Exes ==========================================

EXE := $(BIN_DIR)/so_long

# Compilation ====================================

CC := cc
LDFLAGS ?= -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
CFLAGS ?= -Wall -Wextra -Werror -I$(INC_DIR) -I/usr/include -Imlx_linux -g# -fsanitize=address


# Src files ======================================

HEADERS := 	$(INC_DIR)/so_long.h\
			$(INC_DIR)/get_next_line.h\

SRCS	:= 	$(SRC_DIR)/main.c\
			$(SRC_DIR)/gnl/get_next_line.c\
			$(SRC_DIR)/parsing/check_walls.c\
			$(SRC_DIR)/parsing/check_mid.c\
			$(SRC_DIR)/parsing/check_file_name.c\
			$(SRC_DIR)/parsing/map_to_array.c\
			$(SRC_DIR)/parsing/check_path.c\
			$(SRC_DIR)/parsing/manage_errors.c\
			$(SRC_DIR)/parsing/check_path.c\
			$(SRC_DIR)/parsing/check_path_utils.c\
			$(SRC_DIR)/mlx_work/init_project.c\
			$(SRC_DIR)/mlx_work/manage_keys.c\
			$(SRC_DIR)/mlx_work/texture.c\
			$(SRC_DIR)/mlx_work/clear_project.c\
			$(SRC_DIR)/mlx_work/background.c\


BONUS_SRCS	:= 

# Make all ========================================

all : $(NAME)

$(NAME): so_long

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

# Objects ========================================

OBJS := $(SRCS:.c=.o)

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

# Libs ==========================================

LIBFT := $(LIB_DIR)/libft/libft.a

$(LIBFT) :
	make -C lib/libft -f Makefile

# Recipes ========================================

so_long : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(EXE)

bonus : $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(EXE)

# Cleanup ========================================

clean:
	make -C lib/libft -f Makefile clean
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	make -C lib/libft -f Makefile fclean
	rm -rf $(EXE)

# Additional ========================================

re : fclean all

.PHONY : all clean fclean re