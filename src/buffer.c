/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:38:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/27 18:50:07 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <unistd.h>

static void	*ft_memcpy(void *dst, void const *src, unsigned int n)
{
	unsigned char		*d;
	unsigned char const	*s;
	unsigned int		i;

	d = dst;
	s = src;
	i = 0;
	while (i++ < n)
		*d++ = *s++;
	return (dst);
}

void	server_clear(t_server *server)
{
	free(server->msg);
	server->msg = 0;
	server->msg_len = 0;
	server->buf_len = 0;
}

void	buf_flush(t_server *server)
{
	char	*new_message;
	int		new_size;

	if (server->buf_len == 0)
		return ;
	new_size = server->msg_len + server->buf_len;
	new_message = malloc(sizeof (*new_message) * (new_size + 1));
	if (!new_message)
	{
		server_clear(server);
		error("Memory allocation failed!\n");
	}
	ft_memcpy(new_message, server->msg, server->msg_len);
	ft_memcpy(new_message + server->msg_len, server->buf, server->buf_len);
	free(server->msg);
	server->msg = new_message;
	server->msg_len += server->buf_len;
	server->buf_len = 0;
}

void	buf_append(t_server *server, char c)
{
	if (server->buf_len >= SERVER_BUFFER_SIZE)
		buf_flush(server);
	server->buf[server->buf_len++] = c;
}
