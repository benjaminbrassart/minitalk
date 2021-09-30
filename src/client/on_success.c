/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:24:16 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/30 06:19:14 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "minitalk.h"
#include <stdlib.h>

void	on_success(int sig)
{
	static int	i = 0;

	(void)sig;
	if (++i >= 8)
	{
		if (*_mt()->message == 0)
		{
			ft_printf("Received confirmation from server.\n");
			exit(0);
		}
		i = 0;
	}
}
