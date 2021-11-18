/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_buffer_flush.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:35:50 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/17 23:44:53 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "minitalk_server.h"
#include "mterror.h"
#include <stdlib.h>

void	server_buffer_flush(void)
{
	t_server *const	server = get_server();
	t_size			size;
	char			*new_message;

	size = server->buffer_size;
	if (size == 0)
		return ;
	if (server->message)
		size += ft_strlen(server->message);
	new_message = ft_calloc(size + 1, sizeof (*new_message));
	if (new_message)
	{
		ft_strncat(new_message, server->buffer, server->buffer_size);
		ft_strncat(new_message, server->message, size - server->buffer_size);
		free(server->message);
		server->message = new_message;
		server_buffer_clear();
	}
	else
	{
		print_error(ERROR_MALLOC_FAILED);
		server->error = true;
	}
}
