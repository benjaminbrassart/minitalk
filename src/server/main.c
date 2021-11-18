/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:55:11 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 00:19:03 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "minitalk.h"
#include "minitalk_server.h"
#include "mterror.h"
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	on_signal(int sig, siginfo_t *si, void *ctx __attribute__((unused)))
{
	static int		i = 0;
	static char		c = 0;
	int				bit;

	bit = 0;
	if (sig == SIGUSR2)
		++bit;
	c = (c << 1) | bit;
	if (++i >= 8)
	{
		if (c == 0)
		{
			server_buffer_flush();
			server_message_put();
			server_reset();
		}
		else
			server_message_append(c);
		c = 0;
		i = 0;
	}
	usleep(SLEEP_TIME);
	kill(si->si_pid, SIGUSR1);
}

static t_bool	setup(void)
{
	static struct sigaction	sa = {};

	sa.sa_sigaction = on_signal;
	sa.sa_flags |= SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, FT_NULL) || sigaction(SIGUSR2, &sa, FT_NULL))
	{
		print_error(ERROR_SIGACTION_FAILED);
		return (false);
	}
	return (true);
}

int	main(void)
{
	setup();
	ft_printf("minitalk server is running with pid %d\n\n", getpid());
	while (1)
		pause();
	return (0);
}
