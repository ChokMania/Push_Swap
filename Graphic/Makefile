# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 14:35:33 by anmauffr          #+#    #+#              #
#    Updated: 2019/03/02 14:47:32 by anmauffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= test


CC= gcc
CPPFLAGS=	-I $(INC_PATH)
LDFLAGS=	./libft/
LIBH=		-I $(LDFLAGS)include/
LIBX=		-I /usr/local/include test.c -L /usr/local/lib/ \
			-lmlx -framework OpenGL -framework AppKit
CFLAGS=		-Wall -Wextra -Werror $(LIBX) $(LIBH)

all: lib $(NAME)

lib:
	make -C libft/

$(NAME): $(NAME_OBJ)


$(NAME):