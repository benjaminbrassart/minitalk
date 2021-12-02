/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:47:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/02 02:13:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	server_clear(t_server *server)
{
	server->buf_len = 0;
	server->msg_len = 0;
	server->client_pid = 0;
	free(server->msg);
	server->msg = NULL;
}

void	buf_flush(t_server *server)
{
	char				*msg;

	if (server->buf_len == 0)
		return ;
	msg = malloc(sizeof (*msg) * (server->buf_len + server->msg_len + 1));
	if (!msg)
		exit_error(server->client_pid, ERROR_MALLOC);
	ft_memmove(msg, server->msg, server->msg_len);
	ft_memmove(msg + server->msg_len, server->buf, server->buf_len);
	server->msg_len += server->buf_len;
	server->buf_len = 0;
	free(server->msg);
	server->msg = msg;
}

void	buf_append(t_server *server, char c)
{
	if (server->buf_len >= SERVER_BUFFER_SIZE)
		buf_flush(server);
	server->buf[server->buf_len++] = c;
}
