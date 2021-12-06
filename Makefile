# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 09:57:23 by bbrassar          #+#    #+#              #
#    Updated: 2021/12/06 18:16:35 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT				= client

NAME_SERVER				= server

NAME					= $(NAME_CLIENT) $(NAME_SERVER)

CFLAGS					= -Wall -Werror -Wextra -c -I. -MMD -MP

DIR_SRC					= src

SRC_CLIENT				= client.c utils.c

SRC_SERVER				= server.c utils.c buffer.c

DIR_OBJ					= obj

OBJ_CLIENT				= $(addprefix $(DIR_OBJ)/, $(SRC_CLIENT:.c=.o))

OBJ_SERVER				= $(addprefix $(DIR_OBJ)/, $(SRC_SERVER:.c=.o))

DEPENDENCIES			= $(patsubst %.o,%.d,$(OBJ_CLIENT) $(OBJ_SERVER))

all:					$(NAME)

$(NAME_CLIENT):			$(OBJ_CLIENT)
						$(CC) $^ -o $@

$(NAME_SERVER):			$(OBJ_SERVER)
						$(CC) $^ -o $@

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) $< -o $@

-include $(DEPENDENCIES)

bonus:					all

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME)

re:						fclean all

.PHONY:					all bonus clean fclean re
