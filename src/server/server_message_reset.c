/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_reset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 06:21:23 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/19 03:52:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "minitalk.h"
#include <stdlib.h>

void	server_message_reset(void)
{
	char	**msg;

	msg = _msg();
	free(*msg);
	*msg = FT_NULL;
}
