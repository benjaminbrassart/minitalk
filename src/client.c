/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:32:13 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/02 03:09:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static inline int	ft_strtoi(char const *s, char **end_ptr)
{
	register int	i;

	i = 0;
	while (*s >= '0' && *s <= '9')
		i = i * 10 + *s++ - '0';
	*end_ptr = (char *)s;
	return (i);
}

static void	handle_signal(int signo, siginfo_t *si, void *ctx)
{
	(void)ctx;
	(void)si;
	if (signo == SIGUSR2)
		exit_error(NO_PID, ERROR_SERVER_RESPONSE);
}

static void	send_str(int pid, char const *s)
{
	unsigned int const	len = ft_strlen(s);
	unsigned int		i;
	int					b;
	int					signo;

	i = -1;
	while (++i <= len)
	{
		b = 8;
		while (b--)
		{
			if ((s[i] & (1 << b)) == 0)
				signo = SIGUSR1;
			else
				signo = SIGUSR2;
			kill(pid, signo);
			pause();
		}
		write(1, s[i] == 0 ? "\n" : s + i, 1);
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
	if (*end != 0 || (pid == 0 && argv[1] == end))
		exit_error(NO_PID, ERROR_ARGV_PID);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(pid, argv[2]);
	return (EXIT_SUCCESS);
}
