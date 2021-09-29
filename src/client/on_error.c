/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:23:50 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 07:28:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stdlib.h>

void	on_error(int sig)
{
	(void)sig;
	ft_dprintf(2, "Server sent error signal!\n");
	exit(1);
}
