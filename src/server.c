/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:52:12 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/27 18:52:10 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	error(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	write(2, s, i);
	exit(EXIT_FAILURE);
}

// static void	handle_sig(int sig, siginfo_t *si, void *uctx)
// {
// 	static t_server	server = {{}, 0, NULL, 0};
// 	static int		i = 0;
// 	static char		c = 0;

// 	(void)uctx;
// 	printf("sig: %d\n", sig);
// 	c <<= 1;
// 	if (sig == SIGUSR2)
// 		c |= 1;
// 	if (++i >= 8)
// 	{
// 		if (c == 0)
// 		{
// 			buf_flush(&server);
// 			write(1, server.msg, server.msg_len);
// 			write(1, "\n", 1);
// 			server_clear(&server);
// 		}
// 		else
// 			buf_append(&server, c);
// 		c = 0;
// 		i = 0;
// 	}
// 	usleep(100000);
// 	kill(si->si_pid, SIGUSR1);
// }

static void	handle_sig(int sig, siginfo_t *si, void *uctx)
{
	// static t_server	server = {{}, 0, NULL, 0};
	static int		i = 0;
	static char		c = 0;

	(void)uctx;
	c = (c << 1) | (sig == SIGUSR2);
	if (++i >= 8)
	{
		if (c == 0)
		{
			// buf_flush(&server);
			// write(1, server.msg, server.msg_len);
			// server_clear(&server);
			write(1, "\n", 1);
		}
		else
			write(1, &c, 1);
			// buf_append(&server, c);
		i = 0;
		c = 0;
	}
	kill(si->si_pid, SIGUSR1);
}

static void	print_pid(void)
{
	char	buffer[11];
	int		pid;
	int		cnt;

	pid = getpid();
	cnt = 11;
	while (pid)
	{
		buffer[--cnt] = pid % 10 + '0';
		pid /= 10;
	}
	write(1, buffer + cnt, 11 - cnt);
}

int	main(int argc, char *argv[] __attribute__((unused)))
{
	static struct sigaction	sa = {.sa_flags = SA_SIGINFO,
		.sa_sigaction = handle_sig};

	if (argc != 1)
		error("Expected no argument\n");
	if (sigaction(SIGUSR2, &sa, NULL) || sigaction(SIGUSR1, &sa, NULL))
		error("Failed to install signal handlers");
	write(1, "Server is running with pid ", 27);
	print_pid();
	write(1, "\n\n", 2);
	while (1)
		pause();
}
