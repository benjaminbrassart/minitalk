/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:25:39 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 04:35:19 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "minitalk_client.h"
#include <stdlib.h>

static int	check_int_overflow(int int_val, char const *str_val)
{
	char	*s;
	int		inbound;

	s = ft_itoa(int_val);
	inbound = 0;
	if (s)
	{
		inbound = ft_strcmp(s, str_val) == 0;
		free(s);
	}
	else
		ft_dprintf(2, "ft_itoa() failed!\n");
	return (inbound);
}

static int	check_int_param(char const *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] != 0)
		ft_dprintf(2, "Argument 1 must be a valid integer.\n");
	else if (!check_int_overflow(ft_atoi(str), str))
		ft_dprintf(2, "Argument 1 is outside the limits of signed integers.\n");
	else
		return (1);
	return (0);
}

void	check_args(int argc, char *argv[])
{
	(void)argv;
	if (argc != 3)
		ft_dprintf(2, "Expected 2 arguments, %d given.\n", argc - 1);
	else if (check_int_param(argv[1]))
		return ;
	exit(1);
}
