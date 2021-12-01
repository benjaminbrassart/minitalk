# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 23:57:37 by bbrassar          #+#    #+#              #
#    Updated: 2021/12/02 00:04:31 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS					= -Wall -Werror -Wextra -c -MMD -MP -I.

ifeq ($(DEBUG), true)
CFLAGS					+= -g
endif

NAME_CLIENT				= client

NAME_SERVER				= server

DIR_SRC					= src

SRC_CLIENT				= client.c utils.c

SRC_SERVER				= 

DIR_OBJ					= obj

OBJ_CLIENT				= $(addprefix $(DIR_OBJ)/, $(SRC_CLIENT:.c=.o))

OBJ_SERVER				= $(addprefix $(DIR_OBJ)/, $(SRC_SERVER:.c=.o))

DEPENDENCIES			= $(patsubst %.o,%.d,$(OBJ_CLIENT) $(OBJ_SERVER))

all:					$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):			$(OBJ_CLIENT)
						$(CC) $^ -o $@

$(NAME_SERVER):			$(OBJ_SERVER)
						$(CC) $^ -o $@

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) $< -o $@

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME_CLIENT) $(NAME_SERVER)

re:						fclean all

.PHONY:					all clean fclean re
