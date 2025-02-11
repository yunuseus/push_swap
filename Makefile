NAME := push_swap

CC = cc
CFLAGS = -g

SRC = push_swap.c sorting_utils.c end.c utils.c arg_checks.c extras.c too_many_functions.c

OBJ = $(SRC:.c=.o)

PRINTF = printf/libftprintf.a
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C printf
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C printf
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C printf	
	make fclean -C libft
	rm -f $(NAME)

re: fclean all