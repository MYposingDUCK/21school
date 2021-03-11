CFLAGS = gcc -Wall -Wextra -Werror
NAME = libftprintf.a
EXEC = ft_printf

SRC_DIR = src
SRC_RAW = \
	ft_printf.c \
	ft_print.c \
	parse_flags.c \
	handle_char_and_percent.c \
	tools.c \
	handle_str.c \
	handle_int.c \
	handle_ptr.c \
	handle_hex.c \
	handle_unsigned.c \
	put_width.c


SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_RAW:.c=.o))

HEADER = include/ft_printf.h

all: libft.a $(NAME)

$(BUILD): $(NAME)
	$(CFLAGS) -o $(EXEC)-I "include/" -I "libft/" -L . -lftprintf -L "libft/" -lft

$(NAME): $(OBJ_DIR) $(OBJ)
	cp ./libft/libft.a $(NAME)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

libft.a:
	make -C libft/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CFLAGS) -I "include/" -I "libft/" -c $< -o $@

$(OBJ_DIR):
	mkdir -p$(OBJ_DIR)

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
