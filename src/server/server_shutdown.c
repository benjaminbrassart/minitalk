/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_shutdown.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 05:44:57 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 05:46:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "minitalk_server.h"

void	server_shutdown(void)
{
	get_server()->running = false;
	ft_putnl("Shutdown command received.");
}
