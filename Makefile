SOURCES_COMMUN =	ft_put_string.c \
					ft_put_string2.c \
					ft_itoa_over.c
SOURCES_CLIENT = 	main.c \
					client_handler.c \
					ft_call_server.c
SOURCES_SERVER = 	main.c \
					server.c \
					queue.c

SOURCES_C = $(foreach buffer, $(SOURCES_CLIENT), dclient/$(buffer))

SOURCES_COM = $(foreach buffer, $(SOURCES_COMMUN), commun/$(buffer))

SOURCES_S = $(foreach buffer, $(SOURCES_SERVER), dserver/$(buffer))

OBJS_C = $(SOURCES_C:.c=.o)

OBJS_S = $(SOURCES_S:.c=.o)

OBJS_COM = $(SOURCES_COM:.c=.o)

OBJS_S += $(OBJS_COM)
OBJS_C += $(OBJS_COM)

NAME_S = server
NAME_C = client
NAME = minitalk
LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc

all: $(NAME)

$(NAME_C): $(OBJS_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_C) $(LIBFT) -o $(NAME_C)

$(NAME_S): $(OBJS_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_S) $(LIBFT) -o $(NAME_S)

$(NAME): $(NAME_S) $(NAME_C)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJS_C)
	rm -rf $(OBJS_S)
	make -C libft clean

fclean: clean
	rm -rf $(NAME_C)
	rm -rf $(NAME_S)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
