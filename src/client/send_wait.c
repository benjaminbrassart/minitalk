/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:03:57 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 08:59:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <signal.h>
#include <unistd.h>

int	send_wait(int pid, int sig)
{
	signal(SIGUSR1, on_success);
	signal(SIGUSR2, on_error);
	if (kill(pid, sig) == 0)
	{
		pause();
		return (1);
	}
	return (0);
}
