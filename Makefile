NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c errors.c parser.c stack.c compute_disorder.c \
      utils/ops_swap.c utils/ops_push.c utils/ops_rotate.c \
      utils/ops_rrotate.c utils/alg_simple.c utils/alg_medium.c \
      utils/alg_complex.c utils/alg_adaptive.c utils/bench.c
OBJ = $(SRC:.c=.o)

BONUS_OBJS = bonus/checker_bonus.o bonus/checker_ops_bonus.o
SHARED_OBJS = errors.o parser.o stack.o

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(NAME) $(CHECKER)

$(CHECKER): $(BONUS_OBJS) $(SHARED_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(SHARED_OBJS) $(LIBFT) -o $(CHECKER)

$(BONUS_OBJS): %.o: %.c bonus/checker_bonus.h push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
