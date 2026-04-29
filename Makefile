NAME = push_swap

CC = cc -g
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c errors.c parser.c stack.c compute_disorder.c \
      utils/ops_swap.c utils/ops_push.c utils/ops_rotate.c \
      utils/ops_rrotate.c utils/alg_simple.c utils/alg_medium.c \
      utils/alg_complex.c utils/alg_adaptive.c utils/bench.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
