.PHONY: all, clean, fclean, re, bonus

NAME_SERVER = server
NAME_CLIENT = client
FLAGS = -Wall -Werror -Wextra
DEBUG = 0
ifeq ($(DEBUG), 1)
	FLAGS += -g3 -fsanitize=address
endif

all: $(NAME_SERVER) $(NAME_CLIENT)

LIBFT = libft/libft.a

SRC_SERVER = server.c

SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	cc $^ -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	cc $^ -o $(NAME_CLIENT)
#if hide -> @ before command
$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c
	cc $(FLAGS) -g3 -c $^

clean:
	rm -fr $(OBJ_SERVER) $(OBJ_CLIENT)
	make clean -C libft

fclean: clean
	rm -fr $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C libft

re: fclean all

debug: DEBUG = 1
debug: fclean all
