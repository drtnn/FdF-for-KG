NAME = fdf
LIB_NAME = libft.a
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/
LIB_DIR = libft/

LIB = $(addprefix $(LIB_DIR), $(LIB_NAME))

SRC_FILES =		main.c \
				get_next_line.c \
				file_handler.c \
				file_handler_utils.c \
				line_fun.c \
				dots_fun.c \
				rotation.c \
				math_fun.c \
				key_fun.c \
				key_fun_2.c \
				color_fun.c 
				

HEADERS = $(INC_DIR)fdf.h $(LIB_DIR)libft.h

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I $(INC_DIR) -I $(LIB_DIR)
FRAMEWORKS = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(HEADERS) $(OBJ_DIR) $(OBJ)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(FRAMEWORKS) -o $(NAME)

$(OBJ_DIR):
	@mkdir obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)*
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all

norm:
	@norminette $(SRC) $(HEADERS)
