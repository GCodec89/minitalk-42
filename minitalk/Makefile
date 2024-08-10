# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 21:47:35 by gonolive          #+#    #+#              #
#    Updated: 2024/08/10 11:48:28 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Commands
CC				= cc
RM				= rm -rf

# Flags
CFLAGS			= -Wall -Wextra -Werror -g -Iheaders

# Files
CLIENT 			= client
SERVER 			= server
SRC_CLIENT 		= client.c
SRC_SERVER		= server.c
OBJ_CLIENT		= $(SRC_CLIENT:%.c=%.o)
OBJ_SERVER		= $(SRC_SERVER:%.c=%.o)

LIBFT 			= libft/libft.a

$(LIBFT):
				$(MAKE) -C ./libft

all:			$(CLIENT) $(SERVER)

$(CLIENT):		$(OBJ_CLIENT) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(SERVER):		$(OBJ_SERVER) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(LIBFT)

fclean:         clean
				$(MAKE) fclean -C ./libft
				$(RM) $(CLIENT) $(SERVER)

re:             fclean all

.PHONY:         all clean fclean re