SHELL = bash

# Executable name
PS = push_swap
CH = checker

# Sources, includes and lib names
PS_SRCS_NAME = ft_ps.c \
				ft_others.c \
				ft_choice.c \
				ft_quicksort.c \
				ft_math.c \
				ft_mergesort.c \
				ft_move.c \
				ft_move2.c \
				ft_numbers.c \
				ft_tarace.c \
				ft_tri_5.c

CH_SRCS_NAME = checker.c \
				ft_move.c \
				ft_move2.c \
				ft_move3.c \
				ft_utiles.c \
				ft_apply.c \
				ft_other.c \
				mlx/ft_mlx.c \
				mlx/ft_keyboard.c \
				mlx/ft_print.c \
				mlx/ft_others_mlx.c \
				mlx/ft_color.c

INCS_NAMES = ft_push_swap.h

LDLIBS = libft.a

# Sources, objects, includes and lib path
PS_SRCS_PATH = ./srcs/ps/
PS_OBJS_PATH = ./objs/ps/
CH_SRCS_PATH = ./srcs/checker/
CH_OBJS_PATH = ./objs/checker/
INCS_PATH = ./includes/
LDFLAGS = ./libft/

# Sources and objects
PS_SRCS = $(addprefix $(PS_SRCS_PATH), $(PS_SRCS_NAME))
PS_OBJS = $(patsubst $(PS_SRCS_PATH)%.c, $(PS_OBJS_PATH)%.o, $(PS_SRCS))
CH_SRCS = $(addprefix $(CH_SRCS_PATH), $(CH_SRCS_NAME))
CH_OBJS = $(patsubst $(CH_SRCS_PATH)%.c, $(CH_OBJS_PATH)%.o, $(CH_SRCS))
INC = $(addprefix $(INCS_PATH), $(INCS_NAMES))

# Compilation
CC = gcc
CPPFLAGS = -I $(INCS_PATH)
LIBH = -I $(LDFLAGS)includes/
CFLAGS = -Wall -Wextra -g $(CPPFLAGS) $(LIBH)
MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

# Text format
_DEF = $'\033[0m
_GRAS = $'\033[1m
_SOUL = $'\033[4m
_CLIG = $'\033[5m
_SURL = $'\033[7m

# Colors
_BLACK = $'\033[30m
_RED = $'\033[31m
_GREEN = $'\033[32m
_YELLOW = $'\033[33m
_BLUE = $'\033[34m
_PURPLE = $'\033[35m
_CYAN = $'\033[36m
_GREY = $'\033[37m

# Background
_IBLACK = $'\033[40m
_IRED = $'\033[41m
_IGREEN = $'\033[42m
_IYELLOW = $'\033[43m
_IBLUE = $'\033[44m
_IPURPLE = $'\033[45m
_ICYAN = $'\033[46m
_IGREY = $'\033[47m

verif1 = 0
verif2 = 0

all: lib ps ch

lib:
		@make -sC libft -j100

librm:
		@make -sC libft fclean

ps: $(PS_OBJS)
		@$(CC) $(PS_OBJS) libft/libft.a -o $(PS)

ch: $(CH_OBJS)
		@$(CC) $(CH_OBJS) $(MLX) libft/libft.a -o $(CH)

$(PS): lib $(PS_OBJS)
		@$(CC) $(PS_OBJS) libft/libft.a -o $(PS)

$(CH): lib $(CH_OBJS)
		@$(CC) $(CH_OBJS) $(MLX) libft/libft.a -o $(CH)

$(PS_OBJS_PATH)%.o: $(PS_SRCS_PATH)%.c $(INC)
		@if [[ $(verif1) -eq 0 ]]; then printf "\n\n$(_GRAS)$(_CYAN)|===========================================>  $(PS)  <============================================|$(_DEF)\n";\
		else printf "\e[1A"; fi
		$(eval FNCT = $(words $(PS_SRCS)))
		$(eval verif1 = $(shell echo $(verif1) + 1 | bc ))
		$(eval PCR = $(shell echo "$(verif1) / $(FNCT) * 1000" | bc -l))
		@printf " \n$(_GREEN)[%d%%]\t$(_DEF)%-40s $(_DEF)👉\t\t$(_GREEN) %-40s$(_DEF)" $(shell echo $(PCR) | sed -E "s:\.[0-9]{20}::") $< $@
		@mkdir -p objs/ps
		@printf "$(_DEF)"
		@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(CH_OBJS_PATH)%.o: $(CH_SRCS_PATH)%.c $(INC)
		@if [[ $(verif2) -eq 0 ]]; then printf "\n\n$(_GRAS)$(_CYAN)|===========================================>  $(CH)  <============================================|$(_DEF)\n";\
		else printf "\e[1A"; fi
		$(eval FNCT = $(words $(CH_SRCS)))
		$(eval verif2 = $(shell echo $(verif2) + 1 | bc ))
		$(eval PCR = $(shell echo "$(verif2) / $(FNCT) * 1000" | bc -l))
		@printf " \n$(_GREEN)[%d%%]\t$(_DEF)%-40s $(_DEF)👉\t\t$(_GREEN) %-40s$(_DEF)" $(shell echo $(PCR) | sed -E "s:\.[0-9]{20}::") $< $@
		@mkdir -p objs/checker/mlx
		@printf "$(_DEF)"
		@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
		@echo
		@rm -rf objs/ 2> /dev/null || true
		@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(PS_OBJS_PATH)
		@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(CH_OBJS_PATH)

fclean: clean
		@rm -f $(PS)
		@rm -f $(CH)
		@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(PS)
		@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(CH)
		@echo

fcleanall: librm fclean

re: fclean all

reall: librm re

norme:
		@norminette $(PS_SRCS_PATH)
		@norminette $(CH_SRCS_PATH)
		@norminette $(INCS_PATH)

.PHONY: all lib librm ps ch clean fclean cleanall re reall norme
