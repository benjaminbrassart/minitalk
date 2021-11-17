/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:20:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 18:52:01 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_dputui(int fd, unsigned int n)
{
	int	printed_chars;

	printed_chars = 0;
	if (n >= 10)
	{
		printed_chars = ft_dputui(fd, n / 10);
		if (printed_chars == -1)
			return (-1);
	}
	return (printed_chars + ft_dputc(fd, n % 10 + '0'));
}
