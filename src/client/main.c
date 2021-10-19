/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:51:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/19 03:52:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "minitalk.h"
#include "minitalk_client.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char	**msg;
	int		pid;
	int		i;

	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	msg = _msg();
	*msg = argv[2];
	while (**msg)
	{
		i = send_byte(pid, **msg);
		if (i != 8)
		{
			ft_dprintf(2, "Failed to send byte to server with pid %d.\n", pid);
			exit(1);
		}
		++(*msg);
	}
	send_byte(pid, 0);
	return (0);
}
