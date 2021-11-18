/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:03:57 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 00:17:09 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "ft_stdio.h"
#include "minitalk_client.h"
#include "mterror.h"
#include <signal.h>
#include <unistd.h>

static void	_on_error(int sig __attribute__((unused)))
{
	print_error("! Error");
}

static void	_on_success(int sig __attribute__((unused)))
{
	static int	i = 0;

	ft_putc('.');
	if (++i >= 8)
	{
		if (*get_client()->current_char == 0)
			ft_putnl(SUCCESS " OK" RESET);
		i = 0;
	}
}

t_bool	send_wait(int pid, int sig)
{
	signal(SIGUSR1, _on_success);
	signal(SIGUSR2, _on_error);
	if (kill(pid, sig) == 0)
	{
		pause();
		return (true);
	}
	return (false);
}
