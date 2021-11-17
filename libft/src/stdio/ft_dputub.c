/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:01:10 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 19:12:35 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdio_base.h"
#include "ft_string.h"

static int	_ft_dputub_sz(int fd, unsigned int n, char const *base, t_size sz)
{
	int	printed_chars;

	printed_chars = 0;
	if (n >= 10)
	{
		printed_chars = _ft_dputub_sz(fd, n / sz, base, sz);
		if (printed_chars == -1)
			return (-1);
	}
	return (printed_chars + ft_dputc(fd, base[n % sz]));
}

int	ft_dputub(int fd, unsigned int n, char const *base)
{
	if (!ft_isbasevalid(base))
		return (-1);
	return (_ft_dputub_sz(fd, n, base, ft_strlen(base)));
}
