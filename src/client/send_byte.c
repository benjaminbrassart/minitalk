/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:58:32 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 08:33:58 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "minitalk.h"
#include "minitalk_client.h"
#include <signal.h>
#include <unistd.h>

int	send_byte(int pid, unsigned char byte)
{
	int	i;
	int	sig;

	i = 0;
	while (i < 8)
	{
		if (byte & (1 << (7 - i)))
			sig = SIGUSR2;
		else
			sig = SIGUSR1;
		if (!send_wait(pid, sig))
			break ;
		++i;
		usleep(SLEEP_TIME);
	}
	return (i);
}
