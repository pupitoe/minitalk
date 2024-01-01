SOURCES_CLIENT = 	main.c
SOURCES_SERVER = 	main.c
SOURCES_COMMUN =	ft_put_string.c

SOURCES_C = $(foreach buffer, $(SOURCES_CLIENT), dclient/$(buffer))
SOURCES_COM = $(foreach buffer, $(SOURCES_COMMUN), commun/$(buffer))
SOURCES_S = $(foreach buffer, $(SOURCES_SERVER), dserver/$(buffer))

OBJS_S = $(SOURCES_S:.c=.o)
OBJS_C = $(SOURCES_C:.c=.o)
OBJS_COM = $(SOURCES_COM:.c=.o)

OBJS_S += $(OBJS_COM)
OBJS_C += $(OBJS_COM)

NAME_S = server
NAME_C = client
NAME = minitalk

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc

all: $(NAME)

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME): $(NAME_C) $(NAME_S)

clean:
	rm -rf $(OBJS_C)
	rm -rf $(OBJS_S)

fclean: clean
	rm -rf $(NAME_C)
	rm -rf $(NAME_S)

re: fclean all

.PHONY: all clean fclean re
