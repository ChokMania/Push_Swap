# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judumay <judumay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 11:12:14 by judumay           #+#    #+#              #
#    Updated: 2019/02/07 23:09:15 by judumay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -I includes -I libft/includes/

OBJ = $(SRC:.c=.o)

all: $(NAME)

lib :
	make -C libft/

$(NAME):
	gcc $(CFLAGS) srcs/*.c libft/libft.a -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: clean fclean all