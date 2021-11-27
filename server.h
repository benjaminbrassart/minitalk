/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:52:41 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/27 17:54:16 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# ifndef SERVER_BUFFER_SIZE
#  define SERVER_BUFFER_SIZE 1024
# endif

typedef struct s_server
{
	char	buf[SERVER_BUFFER_SIZE];
	int		buf_len;
	char	*msg;
	int		msg_len;
}	t_server;

void	buf_flush(t_server *server);

void	buf_append(t_server *server, char c);

void	server_clear(t_server *server);

void	error(char const *s);

#endif
