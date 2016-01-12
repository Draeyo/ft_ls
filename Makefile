NAME = ft_ls

SRC = *.c

OBJ = $(SRC:.c=.o)

INC = includes/

LIBDIR = libft

LIB = -lft

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L $(LIBDIR) $(LIB)

$(OBJ): libft
	gcc -c $(SRC) -Wall -Werror -Wextra -I $(INC)

libft:
	$(MAKE) -C $(LIBDIR)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
