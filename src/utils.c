/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:32:26 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/02 03:06:18 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

void	*ft_memmove(void *dst, void const *src, unsigned int n)
{
	unsigned char		*d;
	unsigned char const	*s;
	unsigned int		i;

	d = dst;
	s = src;
	if (src > dst)
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	else
		while (n--)
			d[n] = s[n];
	return (dst);
}

unsigned int	ft_strlen(char const *s)
{
	unsigned int	i;

	i = 0;
	if (s)
		while (s[i])
			++i;
	return (i);
}

void	exit_error(int pid, char const *message)
{
	int	i;

	i = 0;
	while (message[i])
		++i;
	write(2, "\033[31mError: ", 12);
	write(2, message, i);
	write(2, "\033[0m\n", 5);
	if (pid >= 0)
		kill(pid, SIGUSR2);
	printf("pid: %d\n", pid);
	exit(EXIT_FAILURE);
}

void	try_kill(int pid, int signo)
{
	if (kill(pid, signo) == -1)
		exit_error(pid, ERROR_KILL);
}
