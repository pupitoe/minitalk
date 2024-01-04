SOURCES_CLIENT = 	main.c
SOURCES_SERVER = 	main.c \
					server_m.c
SOURCES_COMMUN =	ft_put_string.c \
					ft_put_string2.c \
					ft_memset.c \
					ft_itoa.c
SOURCES_CLIENT_BONUS = 	client_bonus.c \
						client_bonus_handler.c
SOURCES_SERVER_BONUS = 	main.c \
						server_bonus.c

SOURCES_C = $(foreach buffer, $(SOURCES_CLIENT), dclient/$(buffer))
SOURCES_C_BONUS = $(foreach buffer, $(SOURCES_CLIENT_BONUS), dclient/$(buffer))

SOURCES_COM = $(foreach buffer, $(SOURCES_COMMUN), commun/$(buffer))

SOURCES_S = $(foreach buffer, $(SOURCES_SERVER), dserver/$(buffer))
SOURCES_S_BONUS = $(foreach buffer, $(SOURCES_SERVER_BONUS), dserver/$(buffer))

OBJS_C = $(SOURCES_C:.c=.o)
OBJS_C_BONUS = $(SOURCES_C_BONUS:.c=.o)

OBJS_S = $(SOURCES_S:.c=.o)
OBJS_S_BONUS = $(SOURCES_S_BONUS:.c=.o)

OBJS_COM = $(SOURCES_COM:.c=.o)

OBJS_S += $(OBJS_COM)
OBJS_C += $(OBJS_COM)

OBJS_C_BONUS += $(OBJS_COM)
OBJS_S_BONUS += $(OBJS_COM)

NAME_S = server
NAME_C = client
NAME = minitalk

NAME_BONUS = .bonus


CFLAGS = -Wall -Wextra -Werror -g3
CC = cc

all: $(NAME)

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME): $(NAME_C) $(NAME_S)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_C_BONUS) $(OBJS_S_BONUS)
	$(CC) $(CFLAGS) $(OBJS_C_BONUS) -o $(NAME_C)
	$(CC) $(CFLAGS) $(OBJS_S_BONUS) -o $(NAME_S)
	touch $(NAME_BONUS)

clean:
	rm -rf $(OBJS_C)
	rm -rf $(OBJS_S)
	rm -rf $(OBJS_C_BONUS)
	rm -rf $(OBJS_S_BONUS)

fclean: clean
	rm -rf $(NAME_C)
	rm -rf $(NAME_S)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
