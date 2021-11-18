/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:00:45 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 00:00:15 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "minitalk_server.h"

t_server	*get_server(void)
{
	static t_server	server = {false, {}, 0, FT_NULL, -1};

	return (&server);
}
