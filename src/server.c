/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:48:10 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/06 18:57:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "server.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include <stdio.h>

static void	handle_sig(int signo, siginfo_t *si, void *uctx)
{
	static t_server	server = {NULL, 0, {}, 0, 0, 0, 0};

	(void)uctx;
	if (si->si_pid)
		server.client_pid = si->si_pid;
	server.current_char <<= 1;
	if (signo == SIGUSR2)
		server.current_char |= 1;
	if (++server.counter == 8)
	{
		buf_append(&server, server.current_char);
		if (server.current_char == 0)
		{
			buf_flush(&server);
			write(1, server.msg, server.msg_len);
			server_reset(&server);
		}
		server.counter = 0;
		server.current_char = 0;
	}
	usleep(SERVER_SLEEP_TIME);
	if (kill(server.client_pid, SIGUSR1) == -1)
		exit_error(NO_PID, ERROR_KILL);
}

static void	print_pid(void)
{
	int				pid;
	char			buff[36 + 11 + 2];
	unsigned int	i;

	pid = getpid();
	ft_memmove(buff, "Minitalk server is running with pid ", 36);
	i = 0;
	while (pid || i == 0)
	{
		buff[36 + 11 - ++i] = pid % 10 + '0';
		pid /= 10;
	}
	ft_memmove(buff + 36, buff + 36 + 11 - i, i);
	ft_memmove(buff + 36 + i, "\n\n", 2);
	write(1, buff, 36 + i + 2);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		exit_error(NO_PID, ERROR_ARGC_SERVER);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sig;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_pid();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
