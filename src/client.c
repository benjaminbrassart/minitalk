/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:32:13 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/02 00:08:04 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_strtoi(char const *s, char **end_ptr)
{
	int	i;

	i = 0;
	while (*s >= '0' && *s <= '9')
		i = i * 10 + *s++ - '0';
	*end_ptr = (char *)s;
	return (i);
}

static int	ft_strilen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

static void	send_str(int pid, char const *s)
{
	int const	len = ft_strilen(s);
	int			i;
	int			b;
	int			signo;

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
			try_kill(pid, signo);
			pause();
		}
		write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*end;

	if (argc != 3)
		exit_error(ERROR_ARGC);
	pid = ft_strtoi(argv[1], &end);
	if (*end != 0 || (pid == 0 && argv[1] == end))
		exit_error(ERROR_ARGV_PID);
	send_str(pid, argv[2]);
	return (EXIT_SUCCESS);
}
