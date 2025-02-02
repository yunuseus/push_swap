NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC := push_swap.c sorting_utils.c sorting_utils2.c utils.c

OBJ := $(SRC:.c=.o)

PRINTF := printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C printf
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C printf
	rm -f $(NAME)

re: fclean all