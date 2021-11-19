/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:00:45 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 05:32:49 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "minitalk_server.h"

t_server	*get_server(void)
{
	static t_server	server = {false, true, {}, 0, FT_NULL};

	return (&server);
}
