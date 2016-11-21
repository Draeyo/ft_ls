# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/19 14:02:18 by vlistrat          #+#    #+#              #
#    Updated: 2016/11/07 08:04:53 by vlistrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS_PATH = ./srcs/

SRCS_NAME = main.c rights.c time.c ft_error_ls.c ft_ls.c utility.c get_tag.c \
	    display.c ft_alloc_ls.c sort_list.c sort_list_time.c sort.c \
		padding_ls.c sort_list_nstime.c sort_args.c ft_fill.c utility2.c

LIBFT_PATH = ./libft/

LIBFT_NAME = -lft

CC = gcc

INC = ./includes/

CFLAGS = -Wall -Werror -Wextra -I $(INC)

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@(make -C $(LIBFT_PATH))
	@($(CC) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) $(LIBFT_NAME))
	@(echo "\x1b[1;35m$(NAME)\x1b[0m \x1b[32mcreated.\x1b[0m \x1b[1;32m✓\x1b[0m")

%.o: %.c
	@($(CC) -o $@ -c $< $(CFLAGS))

clean: 
	@(/bin/rm -f $(OBJ))
	@(echo "\x1b[1;35mft_ls\x1b[0m object files \x1b[31mcleaned\x1b[0m. \x1b[1;32m✓\x1b[0m")
	@(make -C $(LIBFT_PATH) clean)

fclean: clean 
	@(/bin/rm -f $(NAME))
	@(echo "\x1b[1;35m$(NAME)\x1b[0m \x1b[31mdeleted\x1b[0m. \x1b[1;32m✓\x1b[0m")
	@(make -C $(LIBFT_PATH) fclean)

re: fclean all
