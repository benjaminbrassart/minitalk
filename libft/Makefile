# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 02:36:44 by bbrassar          #+#    #+#              #
#    Updated: 2021/11/18 02:15:00 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a

NAME_SO				= libft.so

CFLAGS				= -Wall -Werror -Wextra -c -MMD -I$(DIR_INCLUDE) \
						-I$(DIR_INCLUDE)/private

LDFLAGS				= 

ifeq ($(DEBUG), true)
CFLAGS				+= -g

LDFLAGS				+= -g
endif

DIR_SRC				= src

SRC					=	$(addsuffix .c, \
							$(addprefix arg/, \
								check_int_limits check_int \
							) \
							$(addprefix ctype/ft_, \
								isalnum isalpha isascii iscntrl isdigit \
								isgraph islower isprint ispunct isspace \
								isupper isxdigit tolower toupper isblank \
							) \
							$(addprefix stdio/ft_, \
								dputc putc dputi puti dputs puts dputui putui \
								dputnl putnl putub dputub \
							) \
							$(addprefix stdio/printf/ft_, \
								patoi get_printer parse_options print_char \
								print_hex print_int print_pointer print_raw \
								print_string print_uint printf dprintf vprintf \
								vdprintf putstr_fn get_printers \
							) \
							$(addprefix list/ft_, \
								lstadd_back lstadd_front lstclear lstdelone \
								lstiter lstiteri lstlast lstmap lstnew lstsize \
							) \
							$(addprefix string/ft_, \
								bzero memccpy memchr memcmp memcpy memmove \
								memrchr memset rawmemchr split strcasecmp \
								strcat strchr strcmp strcpy strcspn strdup \
								strjoin strlcat strlcpy strlen strmapi \
								strncasecmp strncat strncmp strncpy strndup \
								strnlen strnstr strrchr strrepeat strrev \
								strstr strtrim substr strrstr strpbrk strspn \
								stpcpy strchrnul strnew \
							) \
							$(addprefix stdlib/ft_, \
								calloc atoi atoll itoa lltoa strtoi strtol \
								strtoll strtoui strtoul strtoull pmalloc \
								pcalloc \
							) \
							$(addprefix get_next_line/, \
								get_next_line wrap_get_next_line \
							) \
						)

DIR_OBJ				= obj

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

DIR_INCLUDE			= include

DEPENDENCIES		= $(OBJ:.o=.d)

$(NAME):			$(OBJ)
					ar rs $@ $?

-include $(DEPENDENCIES)

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -fPIC $< -o $@

$(NAME_SO):			$(OBJ)
					$(CC) $^ -o $@ -shared -fPIC

all:				$(NAME) $(NAME_SO)

clean:
					rm -rf $(DIR_OBJ)

fclean:				clean
					rm -f $(NAME) $(NAME_SO)

re:					fclean all

.PHONY:				all clean fclean re
