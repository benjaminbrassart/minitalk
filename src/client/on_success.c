/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:24:16 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 08:56:32 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "minitalk.h"
#include <stdlib.h>

void	on_success(int sig __attribute__((unused)))
{
	static int	i = 0;

	ft_putchar('.');
	if (++i >= 8)
	{
		if (*_mt()->message == 0)
		{
			ft_putendl(" OK");
			exit(0);
		}
		i = 0;
	}
}
