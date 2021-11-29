/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:52:12 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/29 16:37:23 by bbrassar         ###   ########.fr       */
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

static void	handle_sig(int sig, siginfo_t *si, void *uctx)
{
	static t_server	server = {0, {}, 0, NULL, 0};
	static int		i = 0;
	static char		c = 0;

	(void)uctx;
	if (si->si_pid)
		server.client_pid = si->si_pid;
	c = (c << 1) | (sig == SIGUSR2);
	if (++i >= 8)
	{
		if (c == 0)
		{
			buf_flush(&server);
			write(1, server.msg, server.msg_len);
			server_clear(&server);
			write(1, "\n", 1);
		}
		else
			buf_append(&server, c);
		i = 0;
		c = 0;
	}
	usleep(25);
	if (kill(server.client_pid, SIGUSR1) == -1)
		error("Failed to send signal\n");
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
	struct sigaction	sa;
	sigset_t			sigset;

	if (argc != 1)
		error("Expected no argument\n");
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigaddset(&sigset, SIGQUIT);
	sa.sa_sigaction = handle_sig;
	sa.sa_mask = sigset;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		error("Failed to install signal handlers");
	write(1, "Server is running with pid ", 27);
	print_pid();
	write(1, "\n\n", 2);
	while (1)
		pause();
}
