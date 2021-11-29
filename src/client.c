/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:31:44 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/27 20:34:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	error(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	write(2, s, i);
	exit(EXIT_FAILURE);
}

static int	ft_strtoi(char const *s, char **end_ptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (*s == '-')
	{
		++s;
		sign = -1;
	}
	while (*s >= '0' && *s <= '9')
		i = i * 10 + *s++ - '0';
	*end_ptr = (char *)s;
	return (i * sign);
}

static void	send_str(int pid, char *message)
{
	int	i;
	int	signo;

	i = 8;
	while (*message)
	{
		while (i--)
		{
			if ((*message & (1 << i)) == 0)
				signo = SIGUSR1;
			else
				signo = SIGUSR2;
			if (kill(pid, signo) == -1)
				error("Failed to send signal\n");
			pause();
		}
		++message;
		i = 8;
	}
	while (i--)
	{
		if (kill(pid, SIGUSR1) == -1)
			error("Failed to send signal\n");
		pause();
	}
}

static void	handle_sig(int sig)
{
	if (sig == SIGUSR2)
		error("Server returned an error\n");
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*end;

	if (argc != 3)
		error("Expected 2 arguments\n");
	pid = ft_strtoi(argv[1], &end);
	if (*end)
		error("Expected argument 1 to be numeric\n");
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	send_str(pid, argv[2]);
	return (EXIT_SUCCESS);
}
