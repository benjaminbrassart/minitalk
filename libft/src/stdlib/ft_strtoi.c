/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:07:52 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/01 12:15:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdlib.h"

int	ft_strtoi(char const *s, char const **endptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
		i = i * 10 + *s++ - '0';
	if (endptr)
		*endptr = s;
	return (i * sign);
}
