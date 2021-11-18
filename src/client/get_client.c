/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:45:39 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/17 22:48:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "minitalk_client.h"

t_client	*get_client(void)
{
	static t_client	client = {-1, FT_NULL, FT_NULL};

	return (&client);
}
