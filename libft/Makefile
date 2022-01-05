# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:25:48 by mpons             #+#    #+#              #
#    Updated: 2021/12/27 18:55:56 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c\
			  ft_isdigit.c\
			  ft_isalnum.c\
			  ft_isascii.c\
			  ft_isprint.c\
			  ft_strlen.c\
			  ft_memset.c\
			  ft_bzero.c\
			  ft_memcpy.c\
			  ft_memmove.c\
			  ft_strlcpy.c\
			  ft_strlcat.c\
			  ft_strcat.c\
			  ft_toupper.c\
			  ft_tolower.c\
			  ft_strchr.c\
			  ft_strrchr.c\
			  ft_strncmp.c\
			  ft_memchr.c\
			  ft_memcmp.c\
			  ft_strnstr.c\
			  ft_atoi.c\
			  ft_calloc.c\
			  ft_strdup.c\
			  ft_substr.c\
			  ft_strjoin.c\
			  ft_strtrim.c\
			  ft_split.c\
			  ft_itoa.c\
			  ft_strmapi.c\
			  ft_striteri.c\
			  ft_putchar_fd.c\
			  ft_putstr_fd.c\
			  ft_putendl_fd.c\
			  ft_putnbr_fd.c\

HEADERS		= libft.h

OBJS		= ${SRCS:.c=.o}

NAME 		= libft.a

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror 

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

RM			= rm -f

LIB			= ar rc 

RAN			= ranlib


${NAME}: 	${OBJS}
		 	${LIB} ${NAME} ${OBJS}
			${RAN} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
