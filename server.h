/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:11:51 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/02 01:57:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "minitalk.h"

# define SERVER_BUFFER_SIZE 1024

typedef struct s_server
{
	char			buf[SERVER_BUFFER_SIZE];
	unsigned int	buf_len;
	char			*msg;
	unsigned int	msg_len;
	int				client_pid;
	int				bit;
	char			chr;
}	t_server;

void	server_clear(t_server *server);

void	buf_append(t_server *server, char c);

void	buf_flush(t_server *server);

#endif
