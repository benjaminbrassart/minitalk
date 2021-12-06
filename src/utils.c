/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:03:26 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/06 11:52:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_memmove(void *dst, void const *src, unsigned int n)
{
	unsigned char		*d;
	unsigned char const	*s;

	d = dst;
	s = src;
	if (s > d)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			d[n] = s[n];
	return (dst);
}

unsigned int	ft_strlen(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	exit_error(int pid, char const *message)
{
	write(2, "\033[31mError: ", 12);
	write(2, message, ft_strlen(message));
	write(2, "\033[0m\n", 5);
	if (pid)
		kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}
