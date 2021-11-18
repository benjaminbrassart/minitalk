/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_buffer_clear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:16:26 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/17 23:45:13 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minitalk_server.h"

void	server_buffer_clear(void)
{
	t_server *const	server = get_server();

	ft_bzero(server->buffer, SERVER_BUFFER_SIZE);
	server->buffer_size = 0;
}
