# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 17:30:16 by mpons             #+#    #+#              #
#    Updated: 2021/12/31 16:34:45 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= So_long

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

OBJS		= ${SRC:.c=.o}

RM			= rm -f

LIBFT_DIR	= ./libft
MLX_DIR		= ./mlx

SRC 		= ./src/so_long.c\
			  ./src/read_map.c\
			  ./src/check_map.c\
		  	  ./src/errors.c\
			  ./src/print_map.c\
			  ./src/key_hook.c\
			  ./src/move.c\
			  ./gnl/get_next_line.c\


INC			= -I./inc -I./libft/libft.h -I./mlx

LIB			= -L ./libft -lft -L ./mlx -lmlx -framework openGL -framework AppKit

all: $(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT_DIR)
			@$(MAKE) -C $(MLX_DIR)
			$(CC) $(CFLAGS) -o $(NAME) $(INC) $(SRC) $(LIB)

norm:
			norminette -d ./gnl ./inc ./libft ./src

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean
		   	$(RM) $(OBJS)

fclean: 
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(MLX_DIR) clean
		   	$(RM) $(OBJS)
	   		$(RM) $(NAME)

re:			fclean all

.PHONY : all clean fclean re bonus
