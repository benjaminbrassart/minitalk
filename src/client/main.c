/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:51:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 00:12:32 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "minitalk.h"
#include "minitalk_client.h"
#include "mterror.h"
#include <stdlib.h>

static void	_init_client(int server_pid, char const *message)
{
	t_client *const	client = get_client();

	client->server_pid = server_pid;
	client->message = message;
	client->current_char = client->message;
}

static t_bool	_send_message(void)
{
	t_client *const	client = get_client();

	while (*client->current_char)
	{
		if (send_byte(client->server_pid, *client->current_char) != 8)
		{
			print_error(ERROR_KILL_FAILED);
			return (false);
		}
		++client->current_char;
	}
	if (send_byte(client->server_pid, 0) != 8)
	{
		print_error(ERROR_KILL_FAILED);
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	int	server_pid;

	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		print_error(ERROR_KILL_GROUP);
		return (EXIT_FAILURE);
	}
	if (server_pid == 1)
	{
		print_error(ERROR_KILL_INIT);
		return (EXIT_FAILURE);
	}
	_init_client(server_pid, argv[2]);
	if (!_send_message())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
