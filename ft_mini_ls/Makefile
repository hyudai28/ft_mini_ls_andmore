NAME = ./ft_mini_ls

SOURCE_FILE = ft_mini_ls.c \
				libft_utilities01.c \
				struct_utilities.c \

OBJECT_FILE = $(SOURCE_FILE:.c=.o)


CC = gcc


CFLAGS = -Wall -Werror -Wextra


all: $(NAME)


.c.o:
		$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJECT_FILE)
	ar rcs $(NAME) $(OBJECT_FILE)

clean:
	rm -f $(OBJECT_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all