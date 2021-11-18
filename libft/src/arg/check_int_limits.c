/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_limits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:48:31 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 02:06:47 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg.h"
#include "ft_ctype.h"
#include "ft_def.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdlib.h>

static t_bool	_check_zero(char const **arg)
{
	unsigned int	i;

	i = 0;
	while ((*arg)[i] == '0')
		++i;
	*arg += i;
	return (i != 0 && (**arg) == 0);
}

t_limit	check_int_limits(char const *arg)
{
	t_limit	limit;
	int		sign;
	int		as_int;
	char	*as_str;

	sign = 1;
	while ((ft_isspace(*arg)))
		++arg;
	if (*arg == '-' || *arg == '+')
		if (*arg++ == '-')
			sign = -1;
	if (_check_zero(&arg))
		return (LIMIT_INBOUND);
	as_int = ft_atoi(arg);
	as_str = ft_itoa(as_int);
	if (!as_str)
		return (LIMIT_ERROR);
	if (ft_strcmp(arg, as_str) == 0)
		limit = LIMIT_INBOUND;
	else if (sign == 1)
		limit = LIMIT_OVERFLOW;
	else
		limit = LIMIT_UNDERFLOW;
	free(as_str);
	return (limit);
}
