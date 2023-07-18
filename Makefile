# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroy <maroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 17:31:16 by maroy             #+#    #+#              #
#    Updated: 2023/07/14 14:42:22 by maroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

MAKELIBFT	= $(MAKE) -C libft/

HEADER_DIR		= includes/
HEADER_SRC		= push_swap.h operations.h
HEADER			= $(addprefix $(HEADER_DIR)/, $(HEADER_SRC))


OPPATH_DIR		= src/operations/
OPPATH_SRC		= op_s.c op_ss.c op_r.c op_revr.c op_p.c op_rr.c op_revrr.c operations.c
OPPATH			= $(addprefix $(OPPATH_DIR)/, $(OPPATH_SRC))
OBJ_OP 			= $(patsubst $(OPPATH_DIR)%.c,obj/%.o,$(OPPATH))


MPATH_DIR		= src/
MPATH_SRC		= main.c checks.c utils.c validate_input.c free.c init.c big_sort.c small_sort.c get_index.c rotate_stack.c
MPATH			= $(addprefix $(MPATH_DIR), $(MPATH_SRC))
OBJ_M 			= $(patsubst $(MPATH_DIR)%.c,obj/%.o,$(MPATH))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
RM			= rm -rf

obj/%.o: $(MPATH_DIR)%.c  $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: $(OPPATH_DIR)%.c  $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ_M) $(OBJ_OP)
			@$(MAKELIBFT)
			@$(CC) $(CFLAGS) $(OBJ_M) $(OBJ_OP) libft/libft.a   -o $(NAME)
			@echo "$(GREEN)$(NAME) created !$(DEFAULT)"


clean:
			$(MAKELIBFT) fclean
			@$(RM) $(OBJ_M) $(OBJ_OP)
			@echo	"$(YELLOW)Obejct files deleted!$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME)
			@echo	"$(RED)All deleted!$(DEFAULT)"  

re:			fclean all

norm:
			@echo "$(DARKGRAY)norminette! $(DEFAULT)"
			norminette $(MPATH)$(UTILS) $(HEADER)

.PHONY:		all clean fclean re norm

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DARKGRAY= \033[1;30m
DEFAULT = \033[1;30m