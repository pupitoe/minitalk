SOURCES = 	main.c \

HEADERS_F = ft_pipex.h

HEADERS = $(foreach buffer, $(HEADERS_F), headers/$(buffer))

OBJS = $(SOURCES:.c=.o)

NAME = pipex 

CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(HEADERS)
	gcc $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

libft: $(LIBFT)

$(LIBFT):
	make -C libft

re: fclean all

.PHONY: all clean fclean re