/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:08:30 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/06 18:52:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_strtoi(char const *s, char **end_ptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s >= '0' && *s <= '9')
		i = i * 10 + *s++ - '0';
	if (end_ptr)
		*end_ptr = (char *)s;
	return (i * sign);
}

static void	handle_sig(int signo, siginfo_t *si, void *uctx)
{
	(void)si;
	(void)uctx;
	if (signo == SIGUSR2)
		exit_error(NO_PID, ERROR_SERVER_RESPONSE);
}

static void	send_str(int pid, char const *s)
{
	unsigned int const	len = ft_strlen(s);
	unsigned int		i;
	int					bit;
	int					signo;
	int					kill_res;

	i = -1;
	while (++i <= len)
	{
		bit = 8;
		while (bit--)
		{
			if ((s[i] & (1 << bit)) == 0)
				signo = SIGUSR1;
			else
				signo = SIGUSR2;
			kill_res = kill(pid, signo);
			if (kill_res == -1)
				exit_error(NO_PID, ERROR_KILL);
			if (usleep(10000) == 0)
				exit_error(NO_PID, "Server timed-out");
		}
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					pid;
	char				*end;

	if (argc != 3)
		exit_error(NO_PID, ERROR_ARGC_CLIENT);
	pid = ft_strtoi(argv[1], &end);
	if (*end || (pid == 0 && end == argv[1]))
		exit_error(NO_PID, ERROR_PID_CLIENT);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sig;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(pid, argv[2]);
	return (EXIT_SUCCESS);
}
