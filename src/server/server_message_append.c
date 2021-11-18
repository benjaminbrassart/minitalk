/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_append.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 05:26:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 00:00:55 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "minitalk.h"
#include "minitalk_server.h"
#include "mterror.h"
#include <stdlib.h>

void	server_message_append(char byte)
{
	t_server *const	server = get_server();

	if (server->buffer_size == SERVER_BUFFER_SIZE)
		server_buffer_flush();
	server->buffer[server->buffer_size++] = byte;
}
