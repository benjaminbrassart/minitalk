/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 06:21:23 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 05:41:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "ft_string.h"
#include "minitalk.h"
#include "minitalk_server.h"
#include <stdlib.h>

void	server_reset(void)
{
	t_server *const	server = get_server();

	server_buffer_clear();
	free(server->message);
	server->message = FT_NULL;
}
