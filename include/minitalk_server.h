/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 04:53:01 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 05:59:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

# include "ft_def.h"
# include "minitalk.h"

# define SHUTDOWN_COMMAND "I command you to stop"

# ifndef SERVER_BUFFER_SIZE
#  define SERVER_BUFFER_SIZE 32UL
# endif
# if SERVER_BUFFER_SIZE < 1
#  error "Minimum SERVER_BUFFER_SIZE is 1!"
# endif

typedef struct s_server	t_server;

struct s_server
{
	t_bool	error;
	t_bool	running;
	char	buffer[SERVER_BUFFER_SIZE];
	t_size	buffer_size;
	char	*message;
};

void		server_buffer_clear(void);

void		server_buffer_flush(void);

void		server_message_append(char byte);

void		server_message_put(void);

void		server_reset(void);

void		server_shutdown(void);

t_server	*get_server(void);

int			get_bit(int sig);

#endif
