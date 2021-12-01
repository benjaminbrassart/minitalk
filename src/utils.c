/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:32:26 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/01 23:39:57 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	exit_error(char const *message)
{
	int	i;

	i = 0;
	while (message[i])
		++i;
	write(2, "\033[31mError: ", 12);
	write(2, message, i);
	write(2, "\033[0m\n", 5);
	exit(EXIT_FAILURE);
}

void	try_kill(int pid, int signo)
{
	if (kill(pid, signo) == -1)
		exit_error(ERROR_KILL);
}
