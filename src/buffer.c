/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:03:20 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/06 12:40:49 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "server.h"
#include <stdlib.h>

void	server_reset(t_server *server)
{
	server->buf_len = 0;
	free(server->msg);
	server->msg = NULL;
	server->msg_len = 0;
}

void	buf_flush(t_server *server)
{
	char	*msg;

	if (server->buf_len == 0)
		return ;
	msg = malloc(server->msg_len + server->buf_len + 1);
	if (!msg)
		exit_error(server->client_pid, ERROR_MALLOC);
	ft_memmove(msg, server->msg, server->msg_len);
	ft_memmove(msg + server->msg_len, server->buf, server->buf_len);
	server->msg_len += server->buf_len;
	server->buf_len = 0;
	msg[server->msg_len] = 0;
	free(server->msg);
	server->msg = msg;
}

void	buf_append(t_server *server, char c)
{
	if (server->buf_len >= SERVER_BUFFER_SIZE)
		buf_flush(server);
	if (c == 0)
		c = '\n';
	server->buf[server->buf_len++] = c;
}
