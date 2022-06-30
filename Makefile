NAME = push_swap
BONUS = checker
MAINSOURCE = \
	push_swap.c
SOURCES = \
	check_args.c sort.c sort_many.c moves_swap.c \
	moves_push.c moves_rotate.c moves_reverse.c moves_others.c \
	convert_numbers.c sort_many_swap_push.c sort_many_push_back.c \
	sort_many_best_start.c sort_many_count_rotations.c utils.c
BMAINSOURCE = \
	checker.c
MAINOBJECT = $(MAINSOURCE:.c=.o)
OBJECTS = $(SOURCES:.c=.o)
BMAINOBJECT = $(BMAINSOURCE:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MAINOBJECT) $(OBJECTS)
	make -C libft
	mv libft/libft.a .
	$(CC) -o $(NAME) $(CFLAGS) $(MAINOBJECT) $(OBJECTS) -L. -lft

bonus: all $(BONUS)

$(BONUS): $(MAINOBJECT) $(OBJECTS) $(BMAINOBJECT)
	$(CC) -o $(BONUS) $(CFLAGS) $(BMAINOBJECT) $(OBJECTS) -L. -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(MAINOBJECT) $(OBJECTS) $(BMAINOBJECT)
	make clean -C libft
	rm -f libft.a

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
