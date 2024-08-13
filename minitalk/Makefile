# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 21:47:35 by gonolive          #+#    #+#              #
#    Updated: 2024/08/12 16:20:56 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Commands
CC					= cc
RM					= rm -rf

# Flags
CFLAGS				= -Wall -Wextra -Werror -g -Iheaders

# Files
CLIENT 				= client
SERVER 				= server
OBJ_CLIENT			= client.o
OBJ_SERVER			= server.o

CLIENT_BONUS 		= client_bonus
SERVER_BONUS		= server_bonus
OBJ_CLIENT_BNS		= client_bonus.o
OBJ_SERVER_BNS		= server_bonus.o

LIBFT	 			= libft/libft.a

$(LIBFT):
					$(MAKE) -C ./libft

all:				$(CLIENT) $(SERVER)

$(CLIENT):			$(OBJ_CLIENT) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(SERVER):			$(OBJ_SERVER) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

clean:
					$(MAKE) clean -C ./libft
					$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BNS) $(OBJ_SERVER_BNS) $(LIBFT)

fclean:     	    clean
					$(MAKE) fclean -C ./libft
					$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

bonus:				$(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS):	$(OBJ_CLIENT_BNS) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_CLIENT_BNS) $(LIBFT) -o $(CLIENT_BONUS)

$(SERVER_BONUS):	$(OBJ_SERVER_BNS) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_SERVER_BNS) $(LIBFT) -o $(SERVER_BONUS)

re:             	fclean all

.PHONY:         	all clean fclean re