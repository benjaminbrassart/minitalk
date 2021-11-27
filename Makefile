# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 16:00:04 by bbrassar          #+#    #+#              #
#    Updated: 2021/11/27 16:59:36 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT				= client

NAME_SERVER				= server

CFLAGS					= -Wall -Werror -Wextra -c  -I. -MMD -MP

ifeq ($(DEBUG), true)
CFLAGS					+= -g
endif

DIR_SRC					= src

SRC_CLIENT				= client.c

SRC_SERVER				= server.c buffer.c

DIR_OBJ					= obj

OBJ_CLIENT				= $(addprefix $(DIR_OBJ)/, $(SRC_CLIENT:.c=.o))

OBJ_SERVER				= $(addprefix $(DIR_OBJ)/, $(SRC_SERVER:.c=.o))

DEPENDENCIES			= $(patsubst %.o,%.d,$(OBJ_CLIENT) $(OBJ_SERVER))

all:					$(NAME_CLIENT) $(NAME_SERVER)

-include $(DEPENDENCIES)

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) $< -o $@

$(NAME_CLIENT):			$(OBJ_CLIENT)
						$(CC) $^ -o $@

$(NAME_SERVER):			$(OBJ_SERVER)
						$(CC) $^ -o $@

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME_CLIENT) $(NAME_SERVER)

re:						fclean all

.PHONY:					all clean fclean re
