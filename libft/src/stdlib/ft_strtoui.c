/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:14:41 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/01 12:17:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdlib.h"

unsigned int	ft_strtoui(char const *s, char const **endptr)
{
	unsigned int	n;

	n = 0;
	while (ft_isspace(*s))
		++s;
	if (*s == '+')
		++s;
	while (ft_isdigit(*s))
		n = n * 10 + *s++ - '0';
	if (endptr)
		*endptr = s;
	return (n);
}
