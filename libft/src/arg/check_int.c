/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:44:32 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 00:48:12 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg.h"
#include "ft_ctype.h"

t_bool	check_int(char const *arg)
{
	int	index;

	index = 0;
	while (ft_isspace(*arg))
		++arg;
	if (*arg == '+' || *arg == '-')
		++arg;
	while (ft_isdigit(arg[index]))
		++index;
	return (arg[index] == 0 && index != 0);
}
