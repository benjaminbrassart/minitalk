/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:00:56 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/22 14:15:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_size	ft_itoa_size(int n)
{
	t_size			sz;

	sz = 1;
	while (n / 10)
	{
		++sz;
		n /= 10;
	}
	return (sz);
}

char	*ft_itoa(int n)
{
	t_size			sz;
	unsigned int	num;
	char			*s;

	sz = ft_itoa_size(n);
	s = ft_calloc(sz + !!(n < 0) + 1, sizeof (char));
	if (n < 0)
		num = -n;
	else
		num = n;
	if (s)
	{
		while (sz)
		{
			s[--sz + !!(n < 0)] = (num % 10) + '0';
			num /= 10;
		}
		if (n < 0)
			s[0] = '-';
	}
	return (s);
}
