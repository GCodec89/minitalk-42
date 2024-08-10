# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 11:59:42 by gonolive          #+#    #+#              #
#    Updated: 2024/08/10 10:20:36 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_SRCS		= ft_atoi.c \
					printf/ft_printf.c printf/ft_printnbr.c printf/ft_printptr.c \
					printf/ft_printstr.c printf/ft_putchar.c printf/ft_putptrhex.c \
					printf/ft_utoa.c \
					
LIB_OBJS 		= $(LIB_SRCS:.c=.o)

CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -fPIC

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(LIB_OBJS)
				ar rcs $(NAME) $(LIB_OBJS)

clean:
				$(RM) $(LIB_OBJS)

fclean:         clean
				$(RM) $(NAME)

re:             fclean $(NAME)

.PHONY:         all clean fclean re