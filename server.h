/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:07:27 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/06 18:05:10 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# ifndef SERVER_BUFFER_SIZE
#  define SERVER_BUFFER_SIZE 1024U
# endif

# if SERVER_BUFFER_SIZE < 1
#  error 'SERVER_BUFFER_SIZE' must have a value of at least 1!
# endif

typedef struct s_server		t_server;

struct s_server
{
	char			*msg;
	unsigned int	msg_len;
	char			buf[SERVER_BUFFER_SIZE];
	unsigned int	buf_len;
	int				client_pid;
	unsigned int	counter;
	char			current_char;
};

void	buf_flush(t_server *server);

void	buf_append(t_server *server, char c);

void	server_reset(t_server *server);

#endif
