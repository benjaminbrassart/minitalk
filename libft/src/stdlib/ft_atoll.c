/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:22:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/03 18:25:56 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(char const *s)
{
	long long	l;
	int			sign;

	l = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
		l = l * 10 + *s++ - '0';
	return (l * sign);
}
