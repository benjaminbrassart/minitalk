/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:04:55 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/17 23:33:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "minitalk_server.h"

void	server_message_put(void)
{
	ft_putnl(get_server()->message);
}
