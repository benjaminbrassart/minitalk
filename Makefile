# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 01:04:09 by bbrassar          #+#    #+#              #
#    Updated: 2021/09/29 02:55:32 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# COMMON
#

CFLAGS					= -Wall -Werror -Wextra -c -MMD -I$(DIR_LIBFT)/include \
							-I$(DIR_INCLUDE)

LDFLAGS					= -lft -L$(DIR_LIBFT)

DIR_SRC					= src

DIR_OBJ					= obj

DIR_INCLUDE				= include

DEPENDENCIES			= $($(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_COMMON):.o=.d)

#
# LIBFT
#

DIR_LIBFT				= libft

NAME_LIBFT				= $(DIR_LIBFT)/libft.a

#
# CLIENT
#

NAME_CLIENT				= client

SRC_CLIENT				= main.c

OBJ_CLIENT				= $(addprefix $(DIR_OBJ)/$(NAME_CLIENT)/, $(SRC_CLIENT:.c=.o))

#
# SERVER
#

NAME_SERVER				= server

SRC_SERVER				= main.c

OBJ_SERVER				= $(addprefix $(DIR_OBJ)/$(NAME_SERVER)/, $(SRC_SERVER:.c=.o))



all:					$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):			$(NAME_LIBFT) $(OBJ_CLIENT) $(OBJ_COMMON)
						$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)

$(NAME_SERVER):			$(NAME_LIBFT) $(OBJ_SERVER) $(OBJ_COMMON)
						$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)

$(DIR_LIBFT)/Makefile:
						git submodule init $(DIR_LIBFT)
						git submodule update $(DIR_LIBFT)

-include $(DEPENDENCIES)

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) $< -o $@

$(NAME_LIBFT):			$(DIR_LIBFT)/Makefile
						$(MAKE) -C $(DIR_LIBFT) libft.a clean

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME_CLIENT) $(NAME_SERVER)

re:						fclean all

.PHONY:					all clean fclean re
