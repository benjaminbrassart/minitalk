/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_append.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 05:26:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 08:48:02 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "minitalk.h"
#include "minitalk_server.h"
#include <stdlib.h>

void	server_message_append(char byte)
{
	t_mt *const		mt = _mt();
	char			*new_buffer;
	int				old_size;

	old_size = 0;
	if (mt->message)
		old_size = ft_strlen(mt->message);
	new_buffer = ft_calloc(old_size + 2, sizeof (char));
	if (new_buffer)
	{
		ft_strncpy(new_buffer, mt->message, old_size);
		new_buffer[old_size] = byte;
		free(mt->message);
		mt->message = new_buffer;
	}
	else
	{
		ft_dprintf(2, "Failed to reallocate memory for message.\n");
		server_exit(1);
	}
}
