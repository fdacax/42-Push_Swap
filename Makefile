MAKEFLAGS += -s
NAME = push_swap
CC = cc -g -Wall -Wextra -Werror
RF = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SOURCE = *.c
SOURCE_OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(SOURCE_OBJS)
	$(CC) -o $(NAME) $(SOURCE_OBJS) $(LIBFT)
	@echo "Compilation successful."

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SOURCE_OBJS) : $(SOURCE)
	$(CC) $(FLAGS) -c $(SOURCE)

clean:
	$(RM) $(SOURCE_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Objects removed."

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	@echo "Static Library and Executables removed."

re: fclean all

.SILENT:

.PHONY: all clean fclean re