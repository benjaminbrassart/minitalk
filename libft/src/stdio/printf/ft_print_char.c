/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:35:22 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 03:43:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf_options.h"
#include "ft_printf_functions.h"

int	ft_print_char(t_opt *opt, va_list args)
{
	return (ft_print_raw(opt, va_arg(args, int)));
}
