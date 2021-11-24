# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 01:04:09 by bbrassar          #+#    #+#              #
#    Updated: 2021/11/24 19:34:32 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# COMMON
#

CFLAGS					= -Wall -Werror -Wextra -c -MMD -I$(DIR_LIBFT)/include \
							-I$(DIR_INCLUDE)

LDFLAGS					= -lft -L$(DIR_LIBFT)

ifeq ($(DEBUG), true)
CFLAGS					+= -g

LDFLAGS					+= -g
endif

DIR_SRC					= src

SRC_COMMON				= print_error.c

DIR_OBJ					= obj

OBJ_COMMON				= $(addprefix $(DIR_OBJ)/, $(SRC_COMMON:.c=.o))

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

SRC_CLIENT				= main.c get_client.c check_args.c send_byte.c send_wait.c get_sig.c

OBJ_CLIENT				= $(addprefix $(DIR_OBJ)/$(NAME_CLIENT)/, $(SRC_CLIENT:.c=.o))

#
# SERVER
#

NAME_SERVER				= server

SRC_SERVER				= main.c get_server.c server_buffer_clear.c server_buffer_flush.c \
							server_message_append.c server_message_put.c server_reset.c \
							server_shutdown.c get_bit.c

OBJ_SERVER				= $(addprefix $(DIR_OBJ)/$(NAME_SERVER)/, $(SRC_SERVER:.c=.o))

all:					$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):			$(NAME_LIBFT) $(OBJ_CLIENT) $(OBJ_COMMON)
						$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)

$(NAME_SERVER):			$(NAME_LIBFT) $(OBJ_SERVER) $(OBJ_COMMON)
						$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)

-include $(DEPENDENCIES)

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) $< -o $@

$(NAME_LIBFT):
						$(MAKE) -C $(DIR_LIBFT) DEBUG=$(DEBUG) libft.a

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME_CLIENT) $(NAME_SERVER)

re:						fclean all

.PHONY:					all clean fclean re
