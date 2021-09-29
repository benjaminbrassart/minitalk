/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:51:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 09:23:22 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "minitalk.h"
#include "minitalk_client.h"

int	main(int argc, char *argv[])
{
	t_mt *const	mt = _mt();
	int			pid;

	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	mt->message = argv[2];
	while (*mt->message)
	{
		send_byte(pid, *mt->message);
		++(mt->message);
	}
	send_byte(pid, 0);
	return (0);
}
