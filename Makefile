# Compiler and flags
CC     = cc
CFLAGS = -Wall -Wextra -Werror -g

# Project and source files
NAME   = push_swap
SRCS   = src/main.c src/swap.c src/push.c src/rotate.c src/reverse_rotate.c src/pushswap_utils.c src/radix.c src/min_hunting.c src/bucket.c src/bucket_utils.c src/hunter_seeker.c src/comp_sort.c
OBJS   = $(SRCS:.c=.o)

# Libft
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT): force
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

force:  # Ensures libft is always rebuilt

