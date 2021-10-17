/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:03:02 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/01 12:15:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdlib.h"

long	ft_strtol(char const *s, char const **endptr)
{
	long	l;
	long	sign;

	l = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
		l = l * 10 + *s++ - '0';
	if (endptr)
		*endptr = s;
	return (l * sign);
}
