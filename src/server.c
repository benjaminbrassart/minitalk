/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:10:44 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/02 03:05:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	add_c(char **s_ptr, char c)
{
	unsigned int const	len = ft_strlen(*s_ptr);
	char				*s;

	s = malloc(sizeof (*s) * (len + 2));
	if (c == 0)
		c = '\n';
	if (s)
	{
		ft_memmove(s, *s_ptr, len);
		s[len] = c;
		s[len + 1] = 0;
	}
	free(*s_ptr);
	*s_ptr = s;
}

static void	print_delete(char **s_ptr)
{
	write(1, *s_ptr, ft_strlen(*s_ptr));
	free(*s_ptr);
	*s_ptr = NULL;
}

static void	print_pid_message(void)
{
	int		pid;
	int		cnt;
	char	buffer[46];

	pid = getpid();
	cnt = 0;
	ft_memmove(buffer, "Minitalk server is running with pid ", 36);
	while (pid || !cnt)
	{
		buffer[sizeof(buffer) - ++cnt] = pid % 10 + '0';
		pid /= 10;
	}
	ft_memmove(buffer + 36, buffer + sizeof(buffer) - cnt, cnt);
	write(1, buffer, 36 + cnt);
	write(1, "\n\n", 2);
}

// static void	handle_sig(int signo, siginfo_t *si, void *ctx)
// {
// 	static t_server	server = {{}, 0, NULL, 0, 0, 8, 0};

// 	(void)ctx;
// 	if (si->si_pid)
// 		server.client_pid = si->si_pid;
// 	server.chr <<= 1;
// 	if (signo == SIGUSR2)
// 		server.chr |= 1;
// 	if (--server.bit == 0)
// 	{
// 		buf_append(&server, server.chr);
// 		if (server.chr == 0)
// 		{
// 			buf_flush(&server);
// 			write(1, server.msg, server.msg_len);
// 			write(1, "\n", 1);
// 			server_clear(&server);
// 		}
// 		server.bit = 8;
// 		server.chr = 0;
// 	}
// 	usleep(1000);
// 	try_kill(server.client_pid, SIGUSR1);
// }

static void	handle_sig(int signo, siginfo_t *si, void *ctx)
{
	static int	b = 8;
	static char	c = 0;
	static char	*s = NULL;
	static int	pid = 0;

	(void)ctx;
	if (si->si_pid)
		pid = si->si_pid;
	c = c << 1;
	if (signo == SIGUSR2)
		c |= 1;
	if (--b == 0)
	{
		add_c(&s, c);
		if (!s)
			exit_error(pid, ERROR_MALLOC);
		if (c == 0)
			print_delete(&s);
		b = 8;
		c = 0;
	}
	try_kill(pid, SIGUSR1);
}

int	main(int argc, char *argv[] __attribute__((unused)))
{
	struct sigaction	sa;

	if (argc != 1)
		exit_error(NO_PID, ERROR_ARGC_SERVER);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_pid_message();
	while (1)
		usleep(10);
	return (EXIT_SUCCESS);
}
