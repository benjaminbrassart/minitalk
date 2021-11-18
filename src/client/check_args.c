/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:25:39 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 02:46:04 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg.h"
#include "ft_ctype.h"
#include "ft_def.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "minitalk_client.h"
#include "mterror.h"
#include <stdlib.h>

static t_bool	_check_int_param(char const *str)
{
	int		i;
	t_limit	limit;

	i = 0;
	while (ft_isspace(*str))
		++str;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
		++i;
	limit = check_int_limits(str);
	if (limit == LIMIT_ERROR)
		print_error(ERROR_MALLOC_FAILED);
	else if (limit == LIMIT_INBOUND)
		return (true);
	else
		print_error(ERROR_INVALID_PID);
	return (0);
}

t_bool	check_args(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_error(ERROR_INVALID_ARGUMENTS);
		return (false);
	}
	return (_check_int_param(argv[1]));
}
