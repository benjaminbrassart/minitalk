/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:08:57 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/01 12:15:53 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdlib.h"

long long	ft_strtoll(char const *s, char const **endptr)
{
	long long	ll;
	long long	sign;

	ll = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
		ll = ll * 10 + *s++ - '0';
	if (endptr)
		*endptr = s;
	return (ll * sign);
}
