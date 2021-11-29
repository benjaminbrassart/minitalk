/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:52:41 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/29 16:48:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# ifdef SERVER_BUFFER_SIZE
#  if SERVER_BUFFER_SIZE < 1
#   error 'SERVER_BUFFER_SIZE' must have a value of at least 1!
#  endif
# else
#  define SERVER_BUFFER_SIZE 1024
# endif

typedef struct s_server
{
	int		client_pid;
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
