/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:12:57 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 18:51:58 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <unistd.h>

int	ft_dputc(int fd, int c)
{
	unsigned char const	ch = (unsigned char)c;

	return (write(fd, &ch, 1));
}
