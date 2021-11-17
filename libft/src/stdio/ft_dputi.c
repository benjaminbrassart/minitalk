/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:17:00 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 18:44:54 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <unistd.h>

int	ft_dputi(int fd, int n)
{
	unsigned int	num;
	int				printed_chars;
	int				sub;

	printed_chars = 0;
	if (n < 0)
	{
		printed_chars = ft_dputc(fd, '-');
		if (printed_chars == -1)
			return (-1);
		num = -n;
	}
	else
		num = n;
	sub = ft_dputui(fd, num);
	if (sub == -1)
		return (-1);
	return (printed_chars + sub);
}
